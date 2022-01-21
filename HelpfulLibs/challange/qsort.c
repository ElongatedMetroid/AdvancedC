#include <stdlib.h>
#include <stdio.h>

#define AR_LEN 10

void show_array(double ar[], int size); 
void fill_array(double ar[], int size);
int comp_doubles(const void *, const void *);

int main(void){
    double data[AR_LEN];
    fill_array(data, AR_LEN);

    qsort(data, AR_LEN, sizeof(data[0]), comp_doubles);

    show_array(data, AR_LEN);

    return 0;
}

void show_array(double ar[], int size){
    for(int i = 0; i < size; i++)
        printf("%f\n", ar[i]);

}

void fill_array(double ar[], int size){
    for(int i = 0; i < size; i++)
        ar[i] = (double)(rand() / (rand() + 0.1));
}

int comp_doubles(const void *p1, const void *p2){
    const double *i1 = (const double *)p1;
    const double *i2 = (const double *)p2;
    if(*i1 < *i2)
        return -1;          //element pointed to be p1 goes before the element pointed to by p2
    else if(*i1 == *i2)
        return 0;           //The element pointed to by p1 is equivalent to the element pointed to by p2
    else
        return 1;           //The element pointed to by p1 goes after the element pointed to by p2
}