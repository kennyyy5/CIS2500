#include "../../A3/include/headerA3.h"
void oneLessCar (a3Car ** headLL, int whichOne){
  if(whichOne == 1) {
    struct car *temp;
    temp = *headLL;
    *headLL = NULL;
    free(temp); //frees head of linked list if whichOne is 1
    return;
  } 
  struct car *prev;
  prev = *headLL;
  for(int i =1; i<(whichOne-1);i++){
    prev = prev->nextCar; //goes to position of whichOne
  }
  struct car * temp  = prev->nextCar;
  prev->nextCar = temp->nextCar; //rearranges linked list
  free(temp);  //frees linked list node of whichOne
}
