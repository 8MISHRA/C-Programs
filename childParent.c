#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

typedef struct {
    int x;
} global_t;

global_t *g;

int main(void) {
    g = (global_t*)malloc(sizeof(global_t));
    g->x = 5;

    if (fork() == 0) { // First fork
        if (fork() == 0) { // Second fork
            g->x--;
            printf("a: %d\n", g->x);  // Print a
        } else {
            g->x++;
        }
        wait(NULL);
        g->x++;
        printf("b: %d\n", g->x);  // Print b
    } else {
        g->x = 2 * g->x;
        wait(NULL);
        g->x++;
        printf("c: %d\n", g->x);  // Print c
    }
    
    printf("d: %d\n", g->x);  // Print e

    return 0;
}
