#include<stdio.h>

#include<conio.h>

#include"../include/emp_structure.h"

#include"../include/console.h"

#include<stdlib.h>

#include<string.h>

/* Function to check login adn validate the user */

int test_run_login() {
    /* variable */
    FILE * fp;
    int recsize = sizeof(e);
    char c;
    char admin[] = "cristina"; /* admin */
    char pass[] = {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0',}; /* Password*/
    int user;
    int found = 0; /*to check for user */

    /* functionality to test the code */
    printf("\n===================================");
    printf("\nTest run to test function validate");
    printf("\ninput : user id : 1000000");
    printf("\ninput : password : password");
    printf("\nOutput : system should display error for wrong password");
    printf("\nTesting starts from here");
    printf("\n-----------------------------------------");

    fp = fopen("EMP.DAT", "rb+");
    if (fp == NULL) {
        fp = fopen("EMP.DAT", "wb+");
        if (fp == NULL) {
            printf("Connot open file");
            exit(1);
        }
    }

   /* main logic to execute login */
    /* Enter values for testing */
    user =1000000;

    rewind(fp); /* move cursor to starting position */
    while (fread( & e, recsize, 1, fp) == 1) {
        /* read all records from file */
        if (user == e.id) {
            /* if the entered record match */
            found = 1;
            printf("Please enter your password :");
            for (int i = 0; i < 10; i++) {
                c = getch();
                if ((c == 13) || (c == 10) || (c == 32)) {
                    break;
                }
                pass[i] = c;
                printf("*");
            }

            if (strcmp(pass, e.pass) == 0) {
                system("cls"); /* clear the console window */
                printf("***********************");
                printf("* Welcome ");
                puts(e.name);
                printf("***********************");
                user = e.id;
                getch();
                break;
            } else {
                printf("Wrong password!");
                getch();
                exit(0);
            }

        }
    }
    if (user == 1000000) {
        found = 1;

        /* Value to be tested */
        strcpy(pass,"password");

        if (strcmp(admin, pass) == 0) {
            system("cls"); /* Clear the console window */

            printf("*************************************");

            printf("* Welcome Cristina !!!              *");

            printf("*************************************");
            getche();
            user = 1000000;
        } else {
            printf("\nWrong password");
            printf("\nTest case passed");
            exit(0);
        }
    } else if ((user < 1000000) || (found != 1)) {

        int recsize = sizeof(e);
        printf("Wrong User!");
        getch();
        exit(0);
    }
    fclose(fp);
    return user;
}


