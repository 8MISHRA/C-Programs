#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    // Open "pid.txt" for reading
    FILE *fp = fopen("pid.txt", "r");
    if (fp == NULL) {
        perror("Failed to open pid.txt");
        exit(EXIT_FAILURE);
    }

    int x;
    // Read the integer from the file
    if (fscanf(fp, "%d", &x) != 1) {
        perror("Failed to read integer from pid.txt");
        fclose(fp);
        exit(EXIT_FAILURE);
    }
    fclose(fp);

    // Calculate and print the difference between current PID and x
    printf("%d\n", getpid() - x);

    return 0;
}
