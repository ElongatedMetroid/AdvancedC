#include <stdio.h>
#include <complex.h>

#define __STDC_WANT_LIB_EXT1__

int main()
{
    #ifdef __STDC_NO_COMPLEX__
        printf("Complex numbers are not supported.\n");
        exit(1);
    #else
        printf("Complex numbers are supported.\n\n");

        double complex cx = 1.0 + 3.0*I;
        double complex cy = 1.0 - 4.0*I;

        printf("Working with complex numbers:\n");
        printf("Starting values: cx = %.2f%+.2fi cy = %.2f%+.2fi\n", creal(cx), cimag(cx), creal(cy), cimag(cy));

        double complex sum = cx + cy;
        printf("\nThe sum cx + cy = %.2f%+.2fi\n", creal(sum), cimag(sum));
    #endif

    return 0;
}