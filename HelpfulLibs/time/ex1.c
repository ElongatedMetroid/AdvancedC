#include <stdio.h>
#include <time.h>
#include <math.h>
#include <ctype.h>

int main(void){
    time_t calandar_start = time(NULL);         //initialize calandar time
    clock_t cpu_start = clock();                //initialize processor time
    int count = 0;                              //Count number of loops

    const long long iterations = 10000000000LL;  //loop iteration amount
    char answer = 'y';
    double x = 0.0;

    printf("Initial clock time = %lld initial calandar time = %lld\n", (long long)cpu_start, (long long)calandar_start);

    while(tolower(answer) == 'y'){
        for(long long i = 0LL; i <iterations; ++i)
            x = sqrt(3.14159265);

        printf("%lld square roots completed.\n", iterations*(++count));
        printf("Do you want to run some more(y or n)? \n");
        scanf("\n%c", &answer);
    }

    clock_t cpu_end = clock();
    time_t calendar_end = time(NULL);

    printf("Final clock time = %lld Final calendar time = %lld\n", (long long)cpu_end, (long long)calendar_end);
    printf("CPU time for %lld iterations is %.2f seconds\n", count*iterations, ((double)(cpu_end-cpu_start)/CLOCKS_PER_SEC));
    printf("Elapsed calendar time to execute the program is %8.2lf seconds.\n", difftime(calendar_end, calandar_start));
}