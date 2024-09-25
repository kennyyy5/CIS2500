#include "../../A3/include/headerA3.h"
int lookForCarModelType (struct car * headLL, char key [100]){
  a3Car * ptr = headLL;
  //declares variables
  char model[MAX_LENGTH];
  char type[MAX_LENGTH];
  //sscanf to separate model and type
  sscanf( key, "%s %s", model, type );
  int i = 1;
  int n=-1;
  //searches function 
  while(ptr != NULL){
    if(strcmp(model, ptr->model)==0 && strcmp(type, ptr->type)==0){
      n=i;}
    ptr = ptr->nextCar;
    i++;
  }
  return n;
}
