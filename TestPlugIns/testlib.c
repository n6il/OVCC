#include <agar/core.h>
#include <agar/gui.h>
#include <SDL2/sdl.h>
#include <stdio.h>
#include <stdlib.h>

void *lib;
void (*libfuncHelloWorld)(void);

void *getFunctionPointer(void* lib, const char* funcName)
{
 //
 // Get the function pointer to the function
  void* fptr = SDL_LoadFunction(lib, funcName);
  
  if (!fptr) 
  {
    AG_TextMsg(AG_MSG_INFO, "Could not get function pointer for %s\n  error is: %s\n", funcName, SDL_GetError());
  }
  
  return fptr;
}

int LoadDLL()
{
	char *file = "plugin.dll";

 //
 // Open the dynamic library
  void *lib = SDL_LoadObject(file);

  if (lib == NULL) 
  {
    //
    // Apparently, the library could not be opened
     AG_TextMsg(AG_MSG_INFO, "Could not open %s\n", file);
     return 0;
  }

 //
 // Get the pointers to the functions within the library:
  libfuncHelloWorld = getFunctionPointer(lib, "HelloWorld");
}

void HelloWorld(AG_Event *event)
{
	fprintf(stderr, "In Local:Hello World!\n");
  AG_TextMsg(AG_MSG_INFO, "Local: Hello World!");
}

void libHelloWorld(AG_Event *event)
{
  if (libfuncHelloWorld)
  {
    libfuncHelloWorld();
  }
}

int main(int argc, char** argv) 
{
  if (AG_InitCore(NULL, 0) == -1 || AG_InitGraphics("sdl2") == -1)
  {
      AG_TextMsg(AG_MSG_INFO, "Init failed: %\n", AG_GetError());
      return (1);
  }

  AG_Window *agwin = AG_WindowNew(AG_WINDOW_MAIN);
  AG_WindowSetCaption(agwin, "Test Load DLL");
  AG_WindowSetGeometryAligned(agwin, AG_WINDOW_ALIGNMENT_NONE, 640, 480);
  AG_WindowSetCloseAction(agwin, AG_WINDOW_DETACH);
  AG_LabelNew(agwin, AG_LABEL_EXPAND, "F1 Local:Hello World.\nF2 DLL:Hello World");

  AG_ActionFn(agwin, "F1", HelloWorld, NULL);
  AG_ActionOnKeyUp(agwin, AG_KEY_F1, AG_KEYMOD_ANY, "F1");
  AG_ActionFn(agwin, "F2", libHelloWorld, NULL);
  AG_ActionOnKeyUp(agwin, AG_KEY_F2, AG_KEYMOD_ANY, "F2");

  LoadDLL();

  AG_WindowShow(agwin);
  AG_EventLoop();
}
