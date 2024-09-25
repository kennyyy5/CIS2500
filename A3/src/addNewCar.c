#include "../../A3/include/headerA3.h"
#include <time.h>
typedef struct car carData;
void addNewCar (struct car ** headLL){
//variables declaration
  int year;
  double price;
  char model[MAX_LENGTH];
  char type[MAX_LENGTH]; 
  srand(time(NULL));
//getting user input
  printf("Enter the car model: "); 
  scanf("%s", model);
  printf("Enter the car type: ");
  scanf("%s", type);
  printf("Enter its year of manufacture: ");
  scanf("%d", &year);
  printf("Enter its price: CDN $ ");
  scanf("%lf", &price);
  //create and assign newCar variable
  carData * newCar = malloc(sizeof(carData));
  if (newCar == NULL) {
    printf("Memory allocation failed.\n");
    return;
  }
  newCar->year = year;
  newCar->price = price;
  strcpy(newCar->model,model);
  strcpy(newCar->type,type);
   //assign newCar ->carId
  int len = strlen(model);
  int sum = 0;
  for (int i = 0; i < len; i++){
    sum = sum + model[i];
  }
  newCar->carId = strlen(type) + sum ;

  newCar->nextCar = NULL; //assign newCar->nextCar
   //check if id exists: 
  while (lookForCarId ( *headLL, (newCar->carId)) != -1){
    int x = (rand() % 999) + 1;
    int y = (rand() % 999) + 1;
    newCar->carId = x+y;
   }

    //create actual linked list
  if(*headLL == NULL){
    *headLL = newCar;}
  else{
    carData * ptr;
    ptr = *headLL;
    while(ptr->nextCar !=NULL){
      ptr = ptr->nextCar;
    }
    ptr->nextCar = newCar;  
  }
  printf("Your computer-generated carId is %d \n", newCar->carId); //prints closing line
}
