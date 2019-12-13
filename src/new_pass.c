#include<stdio.h>

#include<conio.h>

#include"../include/emp_structure.h"

#include"../include/console.h"

#include<stdlib.h>

#include<string.h>

/* Funtion to change password */a
void new_pass(int user) {
    char c;
    int i;
    char pass[] = {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0',}; /* password */
    char npass[] = {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0',}; /* new password */
    FILE * fp; /* file pointer */
    long int recsize; /* record size */
    system("cls");
    printf("Hello %sPlease enter your old password : ", e.name);
    for (i = 0; i < 10; i++) {
        c = getch();
        if ((c == 13) || (c == 10) || (c == 32)) {
            break;
        }
        pass[i] = c;
        fp = fopen("EMP.DAT", "rb+");
        if (fp == NULL) {
            fp = fopen("EMP.DAT", "wb+");
            if (fp == NULL) {
                printf("Connot open file");
                exit(1);
            }
        }
        printf("*");
    }

    if (strcmp(e.pass, pass) == 0) {
        for (i = 0; i <= 10; i++) {
            pass[i] = '\0';
        }
        printf("\nPlease enter your new password : ");
        for (i = 0; i < 10; i++) {
            c = getch();
            if ((c == 13) || (c == 10) || (c == 32)) {
                break;
            }
            pass[i] = c;
            printf("*");
        }
        printf("\nPlease re-enter your new password : ");
        for (i = 0; i < 10; i++) {
            c = getch();
            if ((c == 13) || (c == 10) || (c == 32)) {
                break;
            }
            npass[i] = c;
            printf("*");
        }

        if (strcmp(pass, npass) == 0) {
            fp = fopen("EMP.DAT", "rb+");
            if (fp == NULL) {
                fp = fopen("EMP.DAT", "wb+");
                if (fp == NULL) {
                    printf("Connot open file");
                    exit(1);
                }
            }
            rewind(fp);
            while (fread( & e, recsize, 1, fp) == 1) {
                if (e.id == user) {
                    strcpy(e.pass, npass);
                    fseek(fp, -recsize, SEEK_CUR); /* move the cursor 1 step back from current position */
                    fwrite( & e, recsize, 1, fp);
                    printf("\n\nPassword successfully chnaged");
                    getch();
                    break;
                }
            }
            fclose(fp);
        } else {
            printf("\nNew passwords are not matching");
            getch();
        }
    } else {
        printf("\nWrong old password");
        getch();
    }
}
