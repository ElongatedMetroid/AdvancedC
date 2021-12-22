#include <stdio.h>

union student{
    char letterGrade;
    int roundedGrade;
    float exactGrade;
};

int main(){

    union student var1 = {'B', 87, 86.59};
    union student var2;

    printf("Var1 letterGrade: %c\n", var1.letterGrade);
    printf("Var1 roundedGrade: %i\n", var1.roundedGrade);
    printf("Var1 exactGrade: %f\n", var1.exactGrade);

    var2.letterGrade = 'A';
    printf("\nVar2 letterGrade: %c\n", var2.letterGrade);
    var2.roundedGrade = 98;
    printf("Var2 roundedGrade: %i\n", var2.roundedGrade);
    var2.exactGrade = 97.65;
    printf("Var2 exactGrade: %f\n", var2.exactGrade);

    return 0;
}