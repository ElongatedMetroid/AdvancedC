#ifndef STRINGFUNCTIONS_H_
#define STRINGFUNCTIONS_H_

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define IS_ALPHABET(c) (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z')

/*
Prints the frequency of each char in a string

str - string to count 

returns nothing
*/
void amountCharStr(char * str);

/*
Keeps only alphanumerical parts in the string

str - string to search

returns string with only alphabetical characters
*/
char * keepAlpha(char * str);

/*
Gets the length of the string

src - string to get length

returns length of string
*/
unsigned int stringLength(char * str);

/*
Combine two strings

dest - where src will be attached to the end of
src - the string that will be attached to dest

return dest
*/
char * combineStrs(char * dest, char * src);

/*
Copy src into dest

dest - where the contents of src will be
src - the string that will be copyed to dest

return dest
*/
char * stringCopy(char * dest, char * src);

#endif