#include<stdio.h>

#include<conio.h>

#include"../include/emp_structure.h"

#include"../include/console.h"

#include<stdlib.h>

#include<string.h>

/* Function to check login adn validate the user */

int login() {
    /* variable */
    FILE * fp;
    int recsize = sizeof(e);
    char c;
    char admin[] = {"cristina"}; /* admin */
    char pass[] = {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0',}; /* Password*/
    int user;
    int found = 0; /*to check for user */

    fp = fopen("EMP.DAT", "rb+");
    if (fp == NULL) {
        fp = fopen("EMP.DAT", "wb+");
        if (fp == NULL) {
            printf("Connot open file");
            exit(1);
        }
    }

    system("cls"); /* clear window */
    gotoxy(30, 10); /* move the cursor to postion 30, 10 from top-left corner */
    printf("Please enter your user id: ");
    scanf("%d", & user);
    rewind(fp); /* move cursor to starting position */
    while (fread( & e, recsize, 1, fp) == 1) {
        /* read all records from file */
        if (user == e.id) {
            /* if the entered record match */
            found = 1;
            gotoxy(30, 12);
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
                gotoxy(30, 10); /* move the cursor to postion 30, 10 from top-left corner */
                printf("***********************");
                gotoxy(30, 12);
                printf("* Welcome ");
                puts(e.name);
                gotoxy(30, 14); /* move the cursor to postion 30, 10 from top-left corner */
                printf("***********************");
                user = e.id;
                getch();
                break;
            } else {
                gotoxy(30, 20);
                printf("Wrong password!");
                getch();
                exit(0);
            }

        }
    }
    if (user == 1000000) {
        found = 1;
        gotoxy(30, 12);
        printf("Please enter your password :");
        for (int i = 0; i < 10; i++) {
            c = getch();
            if ((c == 13) || (c == 10) || (c == 32)) {
                break;
            }
            pass[i] = c;
            printf("*");
        }

        if (strcmp(admin, pass) == 0) {
            system("cls"); /* Clear the console window */
            gotoxy(30, 10); /* move the cursor to postion 30, 10 from top-left corner */
            printf("*************************************");
            gotoxy(30, 12);
            printf("* Welcome Cristina !!!              *");
            gotoxy(30, 14);
            printf("*************************************");
            getche();
            user = 1000000;
        } else {
            gotoxy(30, 20);
            printf("Wrong password");
            getch();
            exit(0);
        }
    } else if ((user < 1000000) || (found != 1)) {
        gotoxy(30, 20);
        int recsize = sizeof(e);
        printf("Wrong User!");
        getch();
        exit(0);
    }
    fclose(fp);
    return user;
}
