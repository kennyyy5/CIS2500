#include "../../A3/include/headerA3.h"
void sortCarId (struct car ** headLL){
  if (*headLL == NULL || (*headLL)->nextCar == NULL) {
    return; 
  }
  int l = countCars(*headLL);
  for (int i = 0; i < (l - 1); i++) {
    struct car *prev = NULL;
    struct car *current = *headLL;
    struct car *next = (*headLL)->nextCar;
    for (int j = 0; j < l - 1 - i; j++) {
      if (current->carId > next->carId) {
        if (prev == NULL) {
          *headLL = next;
        } else {
            prev->nextCar = next;
          }
        current->nextCar = next->nextCar;
        next->nextCar = current;
        prev = next;
        next = current->nextCar;
        } else {
            prev = current;
            current = next;
            next = next->nextCar;
          }
        }
      }

}
