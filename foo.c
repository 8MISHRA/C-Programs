#include <stdio.h>
#include <string.h>
#include "foo.h"

// Function to reverse a string
void reverse(char s[]) 
{
  int right = strlen(s) - 1; 
  int left = 0; 
  // Swap characters from start to end until the middle is reached
  while (left < right) {
    char temp = s[left];
    s[left] = s[right];
    s[right] = temp;

    left++;
    right--;
  }
}
