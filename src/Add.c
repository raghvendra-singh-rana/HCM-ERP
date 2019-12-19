
/**
 * @file ADD.c
 * @brief This file is to add employee record to the emp.dat file.
 *        It asks for valid information such as 1)name of employee
 *        2)age 3)employee designation that can be employee or manager
 *        and all the letters in desig should be in lower case. After
 *        reading all the inputs the system checks if there is any wrong value
 *        it will display an error message using valifate function.
 *        Formatted output is present in "/bin/emp.DAT".
 *        
 *
 */
#include"../include/console.h"

#include"../include/emp_structure.h"

#include"../include/time1.h"

#include<stdio.h>

#include<conio.h>

#include<string.h>

#include<windows.h>

#include"../include/user_name.h"

#include"../include/validate.h"

/* function to add a record of employee to database */

void add(int user) {
    long int recsize = sizeof(e); /* record length */
    FILE * fp; /* file pointer for employee file */
    int error; /* error */
    char another, choice; /* option */
    int tempid = 1000000; /* admin */
    char tname[40]; /* temporary name */

    /* file open */
    fp = fopen("EMP.DAT", "rb+");
    if (fp == NULL) {
        fp = fopen("EMP.DAT", "wb+");
        if (fp == NULL) {
            printf("Connot open file");
            exit(1);
        }
    }


    system("cls"); /* clear screen */
    fseek(fp, 0, SEEK_END);
    another = 'y';
    while (another == 'y') /* if user want to add another record */ {
        system("cls");
        user_name(tempid);
        time1();
        gotoxy(30, 6);
        printf("Add Menu");

        rewind(fp); /* this moves file cursor to start of the file */
        while (fread( & e, recsize, 1, fp) == 1) /* read the file and fetch the record one record per fetch */ {
            tempid = e.id; /* store last employee id */
        }
        e.id = tempid + 1;

        gotoxy(0, 7);
        printf("\nEnter name: ");
        scanf("%s", e.name);
        fflush(stdout);
        fgets(tname, sizeof(e.name), stdin);
        strcat(e.name, tname);
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
            fwrite( & e, recsize, 1, fp); /* write the record in the file */
        }

        printf("\n\nDo you want to add another record(y/n) "); /* option to enter another record */
        fflush(stdin);
        scanf("%c", & another);

    }
    fclose(fp);
    return;
}
