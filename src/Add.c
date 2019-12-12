#include"../include/CONSOLE.h"

#include"../include/EMP_STRUCTURE.h"

#include<stdio.h>

#include<conio.h>

#include<string.h>

#include<windows.h>

#include"../include/user_name.h"

#include"../include/validate.h"

void add() {
  long int recsize = sizeof(e);
  FILE * fp;
  int error;
  char another, choice;
  int tempid = 1000000;
  char tname[40]; /* temporary name */

  fp = fopen("EMP.DAT", "rb+");
  if (fp == NULL) {
    fp = fopen("EMP.DAT", "wb+");
    if (fp == NULL) {
      printf("Connot open file");
      exit(1);
    }
  }

  system("cls");
  fseek(fp, 0, SEEK_END);
  another = 'y';
  while (another == 'y') /// if user want to add another record
  {
    system("cls");
    user_name(tempid);
    time1();
    gotoxy(30, 6);
    printf("Add Menu");

    rewind(fp); ///this moves file cursor to start of the file
    while (fread( & e, recsize, 1, fp) == 1) /// read the file and fetch the record one record per fetch
    {
      tempid = e.id; /// store last employee id
    }
    e.id = tempid + 1;

    gotoxy(0, 7);
    printf("\nEnter name: ");
    scanf("%s",e.name);
    fflush(stdout);
    fgets(tname, sizeof(e.name), stdin);
    strcat(e.name,tname);
    printf("\nEnter Designation(employee,manager): ");
    scanf("%s", & e.desig);
    printf("\nEnter age: ");
    scanf("%d", & e.age);
    printf("\nEnter basic salary: ");
    scanf("%f", & e.bs);
    printf("\nEnter password: ");
    scanf("%s", & e.pass);
    e.lleaves = 25;
    error = validate();
    if (error == 1) {
      break;
    }
    printf("\n\nPlease press 'Y' to enter record of %d : ", e.id);

    choice = getche();
    if ((choice == 'y') || (choice == 'Y')) {
      fwrite( & e, recsize, 1, fp); /// write the record in the file
    }

    printf("\n\nDo you want to add another record(y/n) ");
    fflush(stdin);
    scanf("%c",&another);

  }
  fclose(fp);
  return;
}
