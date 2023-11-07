#include <stdio.h>
#include <stdlib.h>
int main(void){
  int *array;
  int n;
  printf("Please enter the length of the array: \n");
  scanf("%d",&n);
  array = malloc(n*sizeof(int));
  if (array == NULL){
    printf("Couldn't allocate memory\n");
    exit(1);
  }
  for (int i = 0; i < n; i++){
    array[i] = 5;
  }
  for (int i = 0; i < n; i++) {
    printf("%d\n", array[i]);
  }
  free(array);
  return 0;
}
