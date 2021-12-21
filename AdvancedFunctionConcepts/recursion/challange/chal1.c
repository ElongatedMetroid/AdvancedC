#include <stdio.h>

int addNumsInRange(int n);

int main(){
    printf("%i\n", addNumsInRange(5));
    return 0;
}

int addNumsInRange(int n){   //addNumsInRange(1, 5) = 15
    int result = -1;

    if(n == 0)
        return result += 1;
    else   
        result = n + addNumsInRange(n - 1);
}