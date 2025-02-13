#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // For fork() and getpid()
#include <sys/wait.h>  // For wait()

// Define the global structure
typedef struct {
    int x;
} global_t;

global_t *g;  // Global pointer to the structure

int main(void) {
    // Allocate memory for the global structure
    g = (global_t*)malloc(sizeof(global_t));

    g->x = 5;  // Initialize g->x to 5
  	printf("Before any fork call %d",g->x);

    // First fork: create a child process
    if (fork() == 0) {  // Child process
      printf("Before second fork call %d",g->x);
        // Second fork: create a grandchild process
        if (fork() == 0) {  // Grandchild process
          	printf("inside second child processfork call %d",g->x);
            g->x--;  // Decrement g->x
            printf("Grandchild (PID: %d) -> g->x = %d\n", getpid(), g->x);
        } 
        else {  // Child process
          	printf("inside second parent fork call %d",g->x);
            g->x++;  // Increment g->x
          	printf("inside second parent else fork call %d",g->x);
        }
      		printf("inside second parent befor wait fork call %d",g->x);
            wait(NULL);  // Wait for the grandchild to finish
          	printf("inside second parent after wait fork call %d",g->x);
            g->x++;  // Increment g->x after the grandchild
            printf("Child (PID: %d) -> g->x = %d\n", getpid(), g->x);
    } 
    else {  // Parent process
        g->x = 2 * g->x;  // Multiply g->x by 2
      	printf("inside first parent befor wait fork call %d",g->x);
        wait(NULL);  // Wait for the child to finish
      	printf("inside second parent after wait fork call %d",g->x);
        g->x++;  // Increment g->x after the child
        printf("Parent (PID: %d) -> g->x = %d\n", getpid(), g->x);
    }

    // Print final value of g->x from all processes
    printf("Final (PID: %d) -> g->x = %d\n", getpid(), g->x);


    return 0;
}