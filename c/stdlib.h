#include <stdio.h>
#include <stdlib.h>
int main(void) {
  int randomValue, result;
  randomValue = rand();
  result = randomValue % 100;
  return EXIT_SUCCESS;
}
