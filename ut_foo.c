#include <stdio.h>
#include <string.h>
#include "foo.h"

int main() 
{
  int status = 0;
  char line[9];  

  printf("Enter text to reverse (Ctrl+D to end):\n");

  while (fgets(line, sizeof(line), stdin)) {

    // Remove newline character at the end of the input
    line[strcspn(line, "\n")] = '\0';

    reverse(line);

    printf("%s\n", line);

    if ( strcmp(line, "87654321") != 0 ) { go_BYE(-1); }
  }
  printf("SUCCESS\n");

BYE:
  return status;
}

