#include "../../A3/include/headerA3.h"
#include <time.h>
void loadCarData (struct car ** headLL, char fileName [MAX_LENGTH]){
  srand(time(NULL));
 // char temp[MAX_LENGTH];
  FILE *fp;
  fp = fopen (fileName, "r");  //opens fileName
  if (fp == NULL) {
    printf("Failed to open file: %s\n", fileName);
    fclose(fp);
    return;
  }
  //declares variables
  int carId, year;
  double price;
  char model[MAX_LENGTH], type[MAX_LENGTH];
  //reads in data
  while(fscanf(fp,"%d,%25[^,]%*c %25[^,]%*c %d,%lf", &(carId), (model), (type), &(year), &(price)) == 5){  
    struct car *newCar = malloc(sizeof(struct car));
    if (newCar == NULL) {
      printf("Memory allocation failed.\n");
      fclose(fp);
      return;
    }
    newCar->carId = carId;
    strcpy(newCar->model, model);
    strcpy(newCar->type, type);
    newCar->year = year;
    newCar->price = price;
    newCar->nextCar = NULL;
    while (lookForCarId ( *headLL, (newCar->carId)) != -1){
      int x = (rand() % 999) + 1;
      int y = (rand() % 999) + 1;
     newCar->carId = x+y;
    }  //end of while
  //creates linked list
  if((*headLL) == NULL){ 
    *headLL = newCar;
  }  //end of  if
  else{
    a3Car * ptr;
    ptr = *headLL;
    while(ptr->nextCar !=NULL){
      ptr = ptr->nextCar;
    } //end of while
    ptr->nextCar = newCar;
  }   // end of else
  } //end of while
  fclose(fp);
}
