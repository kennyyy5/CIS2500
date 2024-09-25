#include "../../A3/include/headerA3.h"
typedef struct car carData;
#include <locale.h>
void printOne (struct car * headLL, int whichOne){
  carData * ptr;
  ptr = headLL;
  int i = 1;
  setlocale(LC_NUMERIC, "");
  if(ptr == NULL){
    printf("Linked list is empty!");}
  else if(whichOne == 1){ //print head of linked list if linked list only has one element
    printf("Car # %d\n", i);
    printf("   Car id: %d\n", ptr->carId);
    printf("   Model: %s\n", ptr->model);
    printf("   Type: %s\n", ptr->type);
    printf("   Price: CDN$ %'.2lf\n", (ptr->price) );
    printf("   Year: %d\n", ptr->year);
  }
  else{
    for(int k =1;i<whichOne;k++){ //goes to position of node
      ptr = ptr->nextCar;
      i++;
    }
    printf("Car # %d\n", i);  //print all of linked list if linked list has more than one element
    printf("   Car id: %d\n", ptr->carId);
    printf("   Model: %s\n", ptr->model);
    printf("   Type: %s\n", ptr->type);
    printf("   Price: CDN$ %'.2lf\n", (ptr->price) );
    printf("   Year: %d\n", ptr->year);
  }


}
