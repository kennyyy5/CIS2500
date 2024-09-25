#include "../../A3/include/headerA3.h"
#include <locale.h>
typedef struct car carData;
void printAll (struct car * headLL){
  carData * ptr;
  ptr = headLL;
  if(ptr == NULL){
    printf("No cars found"); // print msg if linked list is empty
  }
  int i = 1;
  setlocale(LC_NUMERIC, "");
  while(ptr !=NULL){  //print all of non-empty linked list
    printf("Car # %d\n", i);
    printf("	Car id: %d\n", ptr->carId);
    printf("	Model: %s\n", ptr->model);
    printf("	Type: %s\n", ptr->type);
    printf("	Price: CDN$ %'.2lf\n", (ptr->price) );
    printf("	Year: %d\n", ptr->year);
    ptr = ptr->nextCar;
    i++;
    }
}
