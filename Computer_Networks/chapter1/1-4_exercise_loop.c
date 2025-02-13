#include <stdio.h>


void main()
{
    int fahr, celsius;
    int lower, upper, step;
    lower = 0;
    upper = 300;
    step = 20;
    /* lower limit of temperature scale */
    /* upper limit */
    /* step size */
    fahr = lower;
    while (fahr <= upper) {
        celsius = 5 * (fahr-32) / 9;
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }
}

int Celsius2Fahrenhite(int cel){
    return (((cel * 9) / 5) + 32);
}