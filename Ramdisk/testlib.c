#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

void* getFunctionPointer(void* lib, const char* funcName) {
 //
 // Get the function pointer to the function
    void* fptr = dlsym(lib, funcName);
    if (!fptr) {
      fprintf(stderr, "Could not get function pointer for %s\n  error is: %s\n\n", funcName, dlerror());
      return NULL;
    }
    return fptr;
}

int main(int argc, char* argv[]) 
{
 //
 // Declare the function pointers:
    void (*fptr_null      )(int);
    void (*fptr_ModuleName)(char*, void*);

 //
 // Open the dynamic library
    void* hdd_lib = dlopen(argv[1],  RTLD_NOW);

    if (!hdd_lib) {
     //
     // Apparently, the library could not be opened
        fprintf(stderr, "Could not open %s\n", argv[1]);
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }

 //
 // Get the pointers to the functions within the library:
    fptr_null      =getFunctionPointer(hdd_lib, "doesNotExist");
    fptr_ModuleName=getFunctionPointer(hdd_lib, "ModuleName");

    if (fptr_ModuleName) fptr_ModuleName("Sample Name", NULL);

}
