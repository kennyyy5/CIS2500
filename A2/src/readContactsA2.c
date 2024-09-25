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
void readContacts (char * fileName){
  FILE * fp;
  char * email;
  char * fName;
  char * lName;
  struct contact cont;
  int id;
  fp=fopen(fileName,"r");
  if(fp==NULL){
    printf("File doesn't exist!");}
  while(fread (&cont, sizeof(struct contact), 1, fp ) == 1){
    fName= malloc(sizeof(char)*(cont.lastNamePosn - cont.firstNamePosn));
    lName= malloc(sizeof(char)*(cont.emailPosn - cont.lastNamePosn));
    email= malloc(sizeof(char)*(cont.next-cont.emailPosn));
    fread (&id, sizeof(int), 1, fp);
    fread (fName , sizeof(char)*(cont.lastNamePosn - cont.firstNamePosn), 1,fp);
    fread (lName , sizeof(char)*(cont.emailPosn - cont.lastNamePosn), 1, fp);
    fread (email , sizeof(char)*(cont.next-cont.emailPosn), 1, fp);
    printf("********************************* \n");
    printf("Employee Id: %d \n", id);
    printf("First Name: %s \n", fName);
    printf("Last Name: %s \n", lName);
    printf("Email: %s \n", email);
    printf("********************************* \n");
    fseek ( fp, cont.next, SEEK_SET );
  }
  fclose(fp);
}
