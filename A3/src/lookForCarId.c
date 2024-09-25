#include "../../A3/include/headerA3.h"
typedef struct car carData;
int lookForCarId (struct car * headLL, int key){
  carData * ptr = headLL;
  int i = 1; //assigns i to count linked list values
  int n=-1; //assigns n to be returned
  //searches linked list for carId
  while(ptr != NULL){
    if(ptr->carId == key){
      n=i;
    }
    ptr = ptr->nextCar;
    i++;
  }
  return n;
}
