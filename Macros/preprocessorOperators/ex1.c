#include <stdio.h>

#define eat(what) puts("Im eating " #what " today")

int main(){
    eat(fruit);
    //puts("Im eating" "fruit" "today")
}