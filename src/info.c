#include<stdio.h>

#include"../include/validate.h"

#include"../include/console.h"

#include"../include/emp_structure.h"

#include<stdlib.h>

#include<conio.h>

#include<string.h>

/* function to display information of employee */

void info(int user) {
    long int recsize = sizeof(e);
    FILE * fp; /* file pointer */

    system("cls");
    /* file open */
    fp = fopen("EMP.DAT", "rb+");
    if (fp == NULL) {
        fp = fopen("EMP.DAT", "wb+");
        if (fp == NULL) {
            printf("Connot open file");
            exit(1);
        }
    }
    rewind(fp); /* set cursoe to starting position */
    while (fread( & e, recsize, 1, fp) == 1) {
        if (user == e.id) {
            printf("Name :");
            puts(e.name);
            gotoxy(0, 1);
            printf("Employee ID : %d \nAge : %d \nDesignation : %s \nBasic Salary: %.2f", e.id, e.age, e.desig, e.bs);
            getch();
        }
    }
    fclose(fp); /* close of file */
}
