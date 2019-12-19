/*
Authors : Abhinandan Sharma(101134722) & Raghvendra Singh Rana(101123931)
Date    : 03-Dec-2019
Program : HCM - ERP : Employee Management System
*/

#include <stdio.h> ///for input output functions like printf, scanf
#include <stdlib.h> //Standard i/o lib
#include <conio.h>
#include <windows.h> ///for windows related functions (not important)
#include <string.h>  ///string operations
#include <time.h>
#include"../include/emp_structure.h"

void test_run_new_pass(int user) {
    char c;
    int i;
    char pass[] = {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0',}; /* password */
    char npass[] = {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0',}; /* new password */
    FILE * fp; /* file pointer */
    long int recsize = sizeof(e); /* record size */
    system("cls");
    printf("\t\t\t\tTest run for change password");
    printf("\nThis test run will change the password for user 1000001 to password");
    printf("\nInput : new password value i.e. cristina");
    printf("\nExpected output : password value changed to cristina");
          fp = fopen("EMP.DAT", "rb+");
        if (fp == NULL) {
            fp = fopen("EMP.DAT", "wb+");
            if (fp == NULL) {
                printf("Connot open file");
                exit(1);
            }
        }

    user = 1000001;
    strcpy(npass,"cristina");
    //printf("Hello %sPlease enter your old password : ", e.name);
    /* for (i = 0; i < 10; i++) {
        c = getch();
        if ((c == 13) || (c == 10) || (c == 32)) {
            break;
        }
        pass[i] = c;
        pass[] = {'c',} */

        strcpy(e.name,"abhi");
        e.id=1000001;
        strcpy(e.pass,"abhi");
        e.age=23;
        strcpy(e.desig,"employee");
        fwrite( & e, recsize, 1, fp);  
        /* Check for old password */

       rewind(fp);
            while (fread( & e, recsize, 1, fp) == 1) {
                if (e.id == user) {
                    printf("\nOld password was : %s", e.pass);

                    /* update the new pasword */
                    strcpy(e.pass, npass);
                    fseek(fp, -recsize, SEEK_CUR); /* move the cursor 1 step back from current position */
                    fwrite( & e, recsize, 1, fp);
                    printf("\nPassword updated");
                    break;
                }
            }
         /* Check for new password */
        rewind(fp);
            while (fread( & e, recsize, 1, fp) == 1) {
                if (e.id == user) {
                    printf("\nNew password was : %s", e.pass);

                    /* check whether changed password is "cristina" */
                    if (strcmp(e.pass,npass)==0){
                        printf("\nActual output is : %s \nTest case passed", e.pass);
                    }
                    else{
                        printf("\nTest case failed");
                    }
                    break;
                }


            }
}

