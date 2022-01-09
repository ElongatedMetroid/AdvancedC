#include "StringFunctions.h"

void amountCharStr(char * str){
    int freq[26] = { 0 };

    for(unsigned int i = 0; str[i] != '\0'; i++)
        freq[str[i] - 'a']++;

    for(unsigned int i = 0; i < 26; i++){
        if(freq[i] != 0)
            printf("%c - %d\n", i + 'a', freq[i]);
    }
}

char * keepAlpha(char * str){
    int len = strlen(str);
    for(int i = 0; i < len; i++){
        if(!(IS_ALPHABET(str[i]))){
            for (int j=i; j<len; j++)
                str[j]=str[j+1];
            len--;
            i--;
        }
    }
    return str;
}

unsigned int stringLength(char * str){
    unsigned int count = 0;
    char ch = '0';
    for(unsigned int i = 0; ch != '\0'; i++){
        ch = str[i];
        count++;
    }
    count--;
    return count;
} 

char * combineStrs(char * dest, char * src){
    dest = malloc(sizeof(dest) + sizeof(src));
    strcat(dest, src);
    
    return dest;
}

char * stringCopy(char * dest, char * src){
    char ch = 'c';
    for(int i = 0; ch != '\0'; i++){
        ch = src[i];
        dest[i] = src[i];
    }
    return dest;
}
