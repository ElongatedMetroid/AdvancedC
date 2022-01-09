//gcc -c StringFunctions.c -o libStringFunctions.o
//ar rcs lib_stringFunctions.a libStringFunctions.o
//ar -t lib_stringFunctions.a
//gcc -c main.c -o main.o
//gcc -o main main.o *.a

#include "StringFunctions.h"

int main(void){
    char * string1 = "This is a cool string";
    char * string2 = "Hello, World!";

    printf("The length of string1 is : %d\n", stringLength(string1));

    printf("Amount of certain chars in string1 : \n");
    amountCharStr(string1);

    return 0;
}