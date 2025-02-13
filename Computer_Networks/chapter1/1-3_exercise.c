#include <stdio.h>
#include <stdlib.h>

int main(){
    float f, c;
    printf("Enter the temperature in Fahrenheit: ");
    scanf("%f", &f);
    c = (5.0/9.0)*(f-32);
    printf("The temperature in Celsius is: %f\n", c);
    return 0;
}