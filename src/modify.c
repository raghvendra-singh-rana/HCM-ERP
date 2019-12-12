#include<stdio.h>
#include"../include/validate.h"
#include"../include/console.h"
#include"../include/emp_structure.h"
#include<stdlib.h>
#include<conio.h>
#include<string.h>

void modify()
{
  int choice; /* option */
  char another;
  int error;
  FILE *fp;
  long int recsize = sizeof(e);
  int count = 0; /* checks for error code */
  int empid; /* Employee id */
  char tname[40]; /* Temporary name */

  another = 'y';
  while(another == 'y'){
    system("cls");
    user_name(1000000);
    time1();
    gotoxy(30,6);
    printf("Modify Screen");
    printf("\n\nEnter the employee id to modify: ");
    scanf("%d", &empid);
    count = 0;
    fp = fopen("EMP.DAT","rb+");
    if(fp == NULL){
        fp = fopen("EMP.DAT","wb+");
        if(fp == NULL)
        {
            printf("Connot open file");
            exit(1);
        }
    }
    rewind(fp); /* set cursor to starting position */
    while(fread(&e,recsize,1,fp)==1){
      if(empid ==e.id){ /* if entered name matches with that in file */
        count = 1;
        printf("\nRecord found with below details :- \n\nName :");
        puts(e.name);
        printf("Age : %d \nBasic Salary : %f \nDesignation : %s",e.age,e.bs,e.desig);
        printf("\n\nPlease enter new details :- \n\nName : ");
        scanf("%s",e.name);
        fflush(stdout);
        fgets(tname, sizeof(e.name), stdin);
        strcat(e.name,tname);
        printf("\nEnter Designation(employee,manager : )");
        scanf("%s", &e.desig);
        printf("\nEnter age: ");
        scanf("%d", &e.age);
        printf("\nEnter basic salary: ");
        scanf("%f", &e.bs);
        error = validate();
        if (error == 1){
          break;
        }
        printf("\nPlease press Y to confirm"); /* ask for confirmation */
        choice = getche();
        if ((choice == 'y')||(choice == 'Y')){
          fseek(fp,-recsize,SEEK_CUR); /* move the cursor 1 step back from current position */
          fwrite(&e,recsize,1,fp); /* override the record */
          break;
        }

      }

    }
    if (count == 0){
      printf("\n\nNo record found with ID : %d",empid); /* if no corresponding record is found */
    }
    printf("\n\nModify another record(y/n)"); /* option to modify another record */
    empid = 0;
    fflush(stdin);
    another = getche();
    system("cls");
    fclose(fp);
  }
  }

