#include "../../A3/include/headerA3.h"
void noMoreCars (a3Car ** headLL){
  char ans;
  //get ans variable
  do{
    printf("Are you sure? Enter either 'y' or 'n' only: ");
    ans = getchar();}
  while(ans != 'y' &&  ans != 'n');
  if(ans == 'y'){
    a3Car * temp = *headLL;
    a3Car*next;
    //remove all values in linked list
    while (temp != NULL) {
      next = temp->nextCar; 
      free(temp); // Free the memory allocated for the current node
      temp = next; // Move to the next node
    }
    //assigns *headLL to NULL because it is now empty
    *headLL = NULL;
    printf("All removed. Linked list is now empty\n");
  }

}
