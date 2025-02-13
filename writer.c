#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    // Get the current process ID
    int x = getpid();
    // printf("test, %d", x);

    // Open "pid.txt" for writing
    FILE *fp = fopen("pid.txt", "w");
    if (fp == NULL) {
        perror("Failed to open pid.txt");
        exit(EXIT_FAILURE);
    }

    // Write (x + 3) to the file
    fprintf(fp, "%d\n", x + 3);
    fclose(fp);

    // Prepare arguments for execv
    char *args[] = {NULL}; // No arguments

    // Execute the "reader" program
    execv("./reader", args);

    // If execv fails, print an error message
    perror("execv failed");

    // The following code will not execute if execv is successful
    if (fork() == 0) {
        printf("%d\n", x - getppid());
    }

    return 0;
}
