#include <stdio.h>
#include <stdlib.h>

#define IS_UPPER(c) (c >= 'A' && c <= 'Z')
#define IS_LOWER(c) (c >= 'a' && c <= 'z')

#define IS_ALPHABET(c) (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z')
#define IS_DIGIT(c) (c >= '0' && c <= '9')

int main(){
    char ch = '\0';

    printf("Enter any character: ");
    ch = getchar();
    
    if(IS_LOWER(ch))
        printf("%c is a lowercase\n", ch);
    else if(IS_UPPER(ch))
        printf("%c is uppercase\n", ch);

    printf("The character %c is %s\n", ch, IS_ALPHABET(ch)? "in the alphabet":"not in the alphabet");

    printf("The character %c is %s\n", ch, IS_DIGIT(ch)? "a digit":"is not a digit");
}