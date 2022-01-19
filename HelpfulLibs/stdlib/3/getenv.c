#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int main(void){
    char *str = NULL;

    assert((str = getenv("HOME")));
    printf("Value of HOME Enviroment Variable : %s\n", str);

    assert((str = getenv("PATH")));
    printf("Value of PATH Enviroment Variable : %s\n", str);

    assert((str = getenv("USER")));
    printf("Value of USER Enviroment Variable : %s\n", str);

    return 0;
}