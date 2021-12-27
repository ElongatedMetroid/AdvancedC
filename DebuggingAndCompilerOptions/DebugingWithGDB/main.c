//use the -g arg to allow gdb

//type 'run' in gdb

//use 'print <var>' to see the values of variables

//by printing the value of 'i' we can see that the 1376'th member of the array was trying to be accesed

//you can set a variable to a certain value by using 'set var i=5'

//if you have multiple variables with the same name do the following 'print main::i' or 'print func::i'

//to set break points do 'break <line num>', press c to continue, to delete a break point use 'clear <line num>'

//use 's' to step through one line at a time 

//type 'quit' to exit gdb

#include <stdio.h>

int main(void){
    const int data[5] = {1, 2, 3, 4, 5};
    int sum = 0;

    for(int i = 0; i >= 0; ++i) //causes a segmentation fault because an out of array bounds error
        sum += data[i];

    printf("sum = %i\n", sum);

    return 0;
}