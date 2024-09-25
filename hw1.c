#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

typedef struct {
    int x;
} global_t;

global_t *g;

int main(void) {
    g = (global_t*)malloc(sizeof(global_t));
    g->x = 5;

    if (fork() == 0) {
        // Child process
        if (fork() == 0) {
            // Grandchild process
            g->x--;
            printf("%d", g->x);
        } else {
            // Child process (parent of grandchild)
            g->x++;
        }
        wait(NULL);
        g->x++;
        printf("%d", g->x);
    } else {
        // Parent process
        g->x = 2 * g->x;
        wait(NULL);
        g->x++;
        printf("%d", g->x);
    }
    
    printf("%d", g->x);
    
    // Free the allocated memory
    free(g);

    return 0;
}
