#include "../../A3/include/headerA3.h"
int main(){
  struct car * head = NULL;  //head of linked list
  int choice = 0;
  int x = 0;  //control variable
//menu options
  while( x==0 ){
    printf("Choose a function between the options below: \n");
    printf("Menu options \n");
    printf("Option 1: addNewCar \n");
    printf("Option 2: loadCarData \n");
    printf("Option 3: printAll \n");
    printf("Option 4: printOne \n");
    printf("Option 5: lookForCarId \n");
    printf("Option 6: lookForCarModelType \n");
    printf("Option 7: countCars \n");
    printf("Option 8: sortCarId \n");
    printf("Option 9: oneLessCar \n");
    printf("Option 10: noMoreCars \n");
    printf("Option 11: esc \n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    if(choice == 1){  //addNewCar function
      addNewCar(&head); // problem here
      x = 0;
    }
    else if(choice == 2){ //loadCarData function
      char filename[MAX_LENGTH];
      printf("What is the file name that holds car data? ");
      scanf("%s", filename);
      loadCarData(&head,filename);
      x = 0;
    }
    else if(choice == 3){  //printAll function
      printAll(head);
      x = 0;
    }
    else if(choice == 4){  //countCars function
      int n = 0;
      int count = countCars(head);
      do{
        printf("What is your value of n position? ");
        scanf("%d", &n);}while(n > count);
      printOne(head, n);
      x = 0;
    }
    else if(choice == 5){ //lookForCarId function
      int id, n;
      printf("What is the value of id you are looking for? ");
      scanf("%d", &id);
      n =lookForCarId(head, id);
      if(n==-1){
        printf("ID doesn't exist in the linked list!\n");}
      else{
        printf("The position is %d\n", n);} 
      x = 0;
    }
    else if(choice == 6){ //lookForCarModelType function
      int n;
      char modelType[100];
      printf("What is the model and type you are looking for? ");
      getchar();
      fgets(modelType, 100, stdin);
      if(modelType[strlen(modelType) - 1] == '\n'){
        modelType[strlen(modelType) - 1] = '\0';} 
      n =lookForCarModelType(head, modelType);
      if(n==-1){
        printf("What you are looking for doesn't exist in the linked list!\n");}
      else{
        printf("The position is %d\n", n);}
      x = 0;
    }
    else if(choice == 8){ //sortCarId function
      sortCarId(&head);
    }
    else if(choice == 7){  //countCars function
      int a;
      a=countCars(head);
      printf("%d",a);
    }
    else if(choice == 10){ //noMoreCars function
      noMoreCars(&head);
    }
    else if(choice == 9){  //oneLessCar function
      int b = 0;
      int no = countCars(head);
      do{
        printf("Currently, there are %d cars. Which one do you want removed? ", no);
        scanf("%d", &b);
      }while(b<=0 || b > no);
      oneLessCar (&head, b);
    }
    else if(choice == 11){  //esc
      x=1;
      printf("Goodbye\n");}

  }
  return 0;
}
