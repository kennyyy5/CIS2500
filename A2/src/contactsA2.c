/*
Student Name: Kehinde Adenuga
Student ID: 1304431
Due Date: March 3, 2024
Course: CIS*2500
I have exclusive control over this submission via my password.
By including this header comment, I certify that:
1) I have read and understood the policy on academic integrity.
2) I have completed Moodle's module on academic integrity.
3) I have achieved at least 80% on the academic integrity quiz
I assert that this work is my own. I have appropriate acknowledged
any and all material that I have used, be it directly quoted or
paraphrased. Furthermore, I certify that this assignment was written
by me in its entirety.
*/
#include "../../A2/include/givenA2.h"
int main(int argc, char * argv[]){  //arguments for main needed
  char choice1[5];
  int choice2;
  printf("Do you wish to enter a new contact (Yes or No)?: ");
  scanf("%s", choice1);
  if(strcmp(choice1, "Yes") == 0){
    createContacts(argv[1]);
  }else if(strcmp(choice1, "No")==0){
    printf("Enter a choice: \n 1 to print, 2 to search, 3 to create more, -1 to exit: ");
    scanf("%d", &choice2);
    if(choice2 == 1){
      readContacts (argv[1]);}
    else if(choice2 ==2){
      int searchID;
      int searchFound;
      printf("Search for Employee Id? ");
      scanf("%d", &searchID);
      while(!(searchID >= 1 && searchID <= 9999)){
        printf("Invalid data \n Search for Employee Id? ");
        scanf("%d", &searchID);} 
        searchFound = searchContacts (argv[1], searchID);
        if(searchFound == 0){ 
          printf("No match found. \n");}
      }
    else if(choice2 == 3){
      createContacts(argv[1]);}
    else if(choice2 == -1){
      printf("Exiting \n");}
   }
  return 0;
}

