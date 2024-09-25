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
void createContacts (char * fileName){
  FILE * fptr;
  fptr=fopen(fileName,"a+");
  fseek ( fptr, 0, SEEK_END );
  int fwhere = ftell(fptr);
  int contactSize = sizeof(struct contact) + fwhere;
  int id=0;
  struct contact cont;

  char * fName;
  char * lName;
  char * email;

  printf("Employee Id: ");
  scanf("%d",&id);
  cont.empIdPosn = contactSize;

  fName = malloc(sizeof(char)*50);
  printf("First Name: ");
  scanf("%s", fName);
  cont.firstNamePosn = contactSize + sizeof(int) ;
  fName = realloc(fName, sizeof(char)*(strlen(fName)+1));

  lName = malloc(sizeof(char)*50);
  printf("Last Name: ");
  scanf("%s", lName);
  lName = realloc(lName, sizeof(char)*(strlen(lName)+1));
  cont.lastNamePosn = cont.firstNamePosn + strlen(fName) + 1 ;

  email = malloc(sizeof(char)*50);
  printf("Email: ");
  scanf("%s", email);
  email = realloc(email,sizeof(char)*(strlen(email)+1));
  cont.emailPosn = cont.lastNamePosn + strlen(lName) + 1 ;

  cont.next = cont.emailPosn + strlen(email) + 1;

  if(id !=0){
    fwrite (&cont, sizeof(struct contact), 1, fptr );
    fwrite (&id, sizeof(int), 1, fptr);
    fwrite (fName, sizeof(char)*strlen(fName) + 1, 1, fptr );
    fwrite (lName, sizeof(char)*strlen(lName) + 1, 1, fptr );
    fwrite (email, sizeof(char)*strlen(email) + 1, 1, fptr );}
  else{
    printf("Sorry, id must be filled");}

  free(fName);
  free(lName);
  free(email);

  fclose(fptr);
}
