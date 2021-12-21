//informs the compiler that a particular function will
//not return control to the calling program when it
//completes execution

//exit() is an example of a _Noreturn function

#include <stdlib.h>
#include <stdnoreturn.h>

noreturn void f(){
    abort();
}

noreturn void g(int i){    //cause undefined behavior if i<=0
    if(i>0) 
        abort();
}