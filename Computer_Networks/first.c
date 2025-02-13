#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(
    int argc,
    char **argv
) 
{
    int n = atoi(argv[1]);
    char *x = NULL;
    double *Y = NULL;

    x = malloc(n);
    strcpy(x, "hello");
    printf("%s\n", x+2);

    Y = malloc(n*sizeof(double));
    int i, j;
    for (i = 0; i<n; i++){
        j = i+1;
        *Y = j;
        // Y++ or ++Y are same in this programm
        // Y[i] = j;
    }
    int *z = (int *)Y;
    i = 0; printf("z[%d] = %d\n", i, z[i]);
    i = 0; printf("z[%d] = %d\n", i, z[i]);
}
