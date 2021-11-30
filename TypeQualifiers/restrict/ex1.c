/*Tells the compiler that a particular pointer is the only reference
to the value it points to. The same value is not referenced by any 
other pointer or variable within that scope. Without the restrict
keyword the compiler has to assume that some other identifier might
have changed the data in between two uses of a pointer (the worst
case). This is a feature not supported by C++*/
#include <malloc.h>

int * restrict intPtrA; //tells the compiler that for the duration of the scope in which intPtrA and B are defined they will never access the same value
int * restrict intPtrB;

int main()
{
   int array[10];
   int * restrict restar = (int *) malloc(10*sizeof(int));
   int *par = array;

   for(int i = 0; i < 10; i++)
   {
       par[i] += 5;
       restar[i] += 5;
       array[i] *= 2;
       par[i] += 3;
       restar[i] += 3;
   }
}