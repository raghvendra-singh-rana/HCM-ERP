#include<stdio.h>

#include"../include/emp_structure.h"

#include<string.h>

#include"../include/console.h"

#include<conio.h>



/* function to validate entries of employee */

int validate() {
    char *tempdesig[2]= {"employee","manager"};
    if (strcmp(e.name, "") == 0) {
        printf("Please enter valid employee name");
        getch();
        return 1;
    }

    /* Validate designation */
    if ((strcmp(e.desig, tempdesig[0]) != 0) && (strcmp(e.desig, tempdesig[1]) != 0)) {
        printf("Please enter valid designation!");
        getch();
        return 1;
    }

    /* Validate age */
    if ((e.age < 18) || (e.age > 120)) {
        printf("Please enter valid age");
        getch();
        return 1;
    }
}
