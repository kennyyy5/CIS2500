#include "../../A3/include/headerA3.h"
int countCars (a3Car * headLL){
  if(headLL==NULL){
    return 0; //return 0 if headLL empty
  }
  int n=0;
  a3Car * ptr;
  ptr = headLL;
  while(ptr !=NULL){ // counts linked list if not empty as n
    ptr = ptr->nextCar;
    n++;
  }
  return n;
}
