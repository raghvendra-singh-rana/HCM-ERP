#include<stdio.h>

#include"../include/emp_structure.h"

#include<string.h>

#include"../include/console.h"

#include<conio.h>


/* function to validate entries of employee */

int test_run_validate() {
    printf("\n===================================");
    printf("\nTest run to test function validate");
    printf("\ninput : designation : professor");
    printf("\nOutput : system should throw error to input valid designation");
    printf("\nTesting starts from here");
    printf("\n-----------------------------------------");

    /* Enter values to be tested */
    strcpy(e.name,"cristina");
    e.age = 25;
    strcpy(e.desig,"professor");

    char *tempdesig[2]= {"employee","manager"};
    if (strcmp(e.name, "") == 0) {
        printf("\nPlease enter valid employee name");
        return 1;
    }

    /* Validate designation */
    if ((strcmp(e.desig, tempdesig[0]) != 0) && (strcmp(e.desig, tempdesig[1]) != 0)) {
        printf("\nPlease enter valid designation!");
        return 1;
    }

    /* Validate age */
    if ((e.age < 18) || (e.age > 120)) {
        printf("\nPlease enter valid age");
        return 1;
    }
}


