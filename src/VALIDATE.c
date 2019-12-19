/**
 * @file VALIDATE.c
 * @brief This file is used to verify the values entered by the 
 *        user that is admin or employee and display apppropriate error message
 *        in case of error
 */
#include<stdio.h>

#include"../include/emp_structure.h"

#include<string.h>

#include"../include/console.h"

#include<conio.h>

#include"../include/add.h"

/* function to validate entries of employee */

int validate() {
    char *tempdesig[2]= {"employee","manager"};
    if (strcmp(e.name, "") == 0) {
        gotoxy(0, 30);
        printf("Please enter valid employee name");
        getch();
        return 1;
    }

    /* Validate designation */
    if ((strcmp(e.desig, tempdesig[0]) != 0) && (strcmp(e.desig, tempdesig[1]) != 0)) {
        gotoxy(0, 30);
        printf("Please enter valid designation!");
        getch();
        return 1;
    }

    /* Validate age */
    if ((e.age < 18) || (e.age > 120)) {
        gotoxy(0, 30);
        printf("Please enter valid age");
        getch();
        return 1;
    }
}
