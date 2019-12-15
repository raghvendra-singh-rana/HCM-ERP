#include<stdio.h>

#include"../include/validate.h"

#include"../include/console.h"

#include"../include/emp_structure.h"

#include"../include/sal_structure.h"

#include"../include/month_convert.h"

#include"../include/user_name.h"

#include<stdlib.h>

#include<conio.h>

#include<string.h>

#include"../include/time1.h"

void pay(int user) {
  /*variables*/
  long int recsize = sizeof(e);
  long int recsizes = sizeof(s);
  FILE *fp, *fs;
  int count;
  int cmon;
  int month;
  int empid;
  float whours;
  int choice;
  char *smon;
  system("cls");
  user_name(user);
  month = time1();

  gotoxy(0, 7);
  printf("Enter the employee id : ");
  scanf("%d", &empid);
  fp = fopen("EMP.DAT", "rb");
  rewind(fp);
 /* Loop to read data from emp.dat file and then matching it and writing in sal.dat file*/
  while (fread( &e, recsize, 1, fp) == 1) {
    if (empid == e.id) {
      count = 1;
      printf("\n\nPlease enter the month in digits : ");
      scanf("%d", & cmon);
      if ((cmon < 1) || (cmon > month)) {
        printf("\nInvalid Month. Going back to main menu");
        getch();
        return;
      } else {
        printf("\nDo you want to add works hours for employee ? Press y to confirm ");
        choice = getche();
        if ((choice == 'y') || (choice == 'Y')) {
          fs = fopen("SAL.DAT", "w");
          printf("\n\nNo of hours worked: ");
          scanf("%f", & whours);
          s.id = empid;
          strcpy(s.name, e.name);
          s.mon = cmon;
          s.hours = whours;
          s.salary = whours * e.bs;
          fwrite( &s, recsizes, 1, fs);
          printf("\n\nSalary added for %d for month %d!", e.id, s.mon);
          getch();
          break;
        }
      }

    }

  }
  fclose(fp);
  fclose(fs);
}


