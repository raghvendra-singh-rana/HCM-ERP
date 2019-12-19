#include<stdio.h>

#include"../include/validate.h"

#include"../include/console.h"

#include"../include/emp_structure.h"

#include<stdlib.h>

#include<conio.h>

#include<string.h>

/* function to delete a employee record */

void delete(int user) {
    /* Variable */
    char another, choice; /* option */
    int count; /*counter */
    int empid; /*Employee id */
    FILE * fp, * ft; /* file pointer */
    long int recsize = sizeof(e); /* size of record */

    system("=================================================================");
    printf("\nTest case for delete function");
    printf("\nFuntion accepts employee id to be deleted");
    printf("\nfor this test case employee id to be delete is 1000001");
    printf("\nInput : 1000001");
    printf("\nExpected output : employe id deleted");
    printf("\nTest starts below");
    printf("\n------------------------");


    /* open file */
    fp = fopen("EMP.DAT", "rb+");
    if (fp == NULL) {
        fp = fopen("EMP.DAT", "wb+");
        if (fp == NULL) {
            printf("Connot open file");
            exit(1);
        }
    }


        /*
         * Enter test values
        */

 empid=1000001;
        ft = fopen("Temp.DAT", "wb+"); /* create a intermediate file for temporary storage */
        rewind(fp); /// move record to starting of file
        while (fread( & e, recsize, 1, fp) == 1) {
            if (empid == e.id) {
                count = 1;
                printf("\nRecord found with below details :- \n\nName :");
                puts(e.name);

                /* Manual entering the choice to 'y' */
                choice = 'y' ;
                if ((choice != 'y') && (choice != 'Y')) {
                    fwrite( & e, recsize, 1, ft);
                }
            } else {
                fwrite( & e, recsize, 1, ft); /* move all records except the one that is to be deleted to temp file */
            }
        }

        fclose(fp);
        fclose(ft);
        remove("EMP.DAT"); /* remove the orginal file */
        rename("Temp.DAT", "EMP.DAT"); /* rename the temp file to original file name */
        fflush(stdin);


    /*Logic to check whether record is deleted */
    printf("\nverifying the record is deleted");
    fp = fopen("EMP.DAT", "rb+");
    if (fp == NULL) {
        fp = fopen("EMP.DAT", "wb+");
        if (fp == NULL) {
            printf("Connot open file");
            exit(1);
        }
    }

    count = 0; /* set counter to 0 */

    rewind(fp); /// move record to starting of file
        while (fread( & e, recsize, 1, fp) == 1) {
            if (empid == e.id) {
                count = 1;
                printf("\nRecord found with below details :- \n\nName :");
                puts(e.name);
                printf("Age : %d \nBasic Salary : %f \nDesignation : %s", e.age, e.bs, e.desig);
                choice = 'y';
                if ((choice != 'y') && (choice != 'Y')) {
                    fwrite( & e, recsize, 1, ft);
                }
            } else {
                fwrite( & e, recsize, 1, ft); /* move all records except the one that is to be deleted to temp file */
            }
            }

     fclose(fp);

        if (count == 1) {
            printf("\nNo record found with ID : %d", empid);
            printf("\nRecord deletion confirmed");
            printf("\nTest case passed");
        }
        else{
            printf("Test case failed");

    }
    printf("\n-----------------------------------------------------");
    fclose(fp);
}



