#include <stdio.h>
#include <complex.h>
#include <math.h>

int main()
{
    double complex cx = (I*I);
    printf("cx: Real, %.2f Imaginary, %.2fi\n", creal(cx), cimag(cx));

    double complex cy = pow(I, 2);
    printf("cy: Real, %.2f Imaginary, %2fi\n", creal(cy), cimag(cy));

    double complex cz = exp(I * M_PI);
    printf("cz: Real, %.2f Imaginary, %2fi\n", creal(cz), cimag(cz));

    double complex ca = 1+2*I;
    double complex cb = 1-2*I;
    printf("ca: Real, %.2f Imaginary, %2fi\n", creal(ca), cimag(ca));
    printf("cb: Real, %.2f Imaginary, %2fi\n", creal(cb), cimag(cb));
    
    return 0;
}