//gcc -g -fPIC myLib.c -shared -o lib_mylib.so
//gcc -c main.c -o main.o
// export LD_LIBRARY_PATH=/media/Stuff500GB/repos/AdvancedC/StaticLibsAndSharedObj/DynamicLibs:$LD_LIBRARY_PATH
//gcc -o main main.o -lmylib

#include <stdio.h>

void fun(void){
    printf("func() called from a dynamic library\n");
}