#include <stdio.h>

int main(void){
  int array[] = {6,5,4,3,2,1,8,10,9,7};
  int length = sizeof array/ sizeof array[0];

  for(int i = 1; i < length; i++){
    int j = i;
    while(j >= 0 && array[j] < array[j-1]){
      int swap = array[j];
      array[j] = array[j-1];
      array[j-1] = swap;
      j--;
    }
  }

  for(int i = 0; i < length; i++)
    printf("%i\n", array[i]);
}