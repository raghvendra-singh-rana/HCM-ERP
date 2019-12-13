#include<stdio.h>

#include"../include/console.h"

#include"../include/emp_structure.h"

#include<stdlib.h>

#include<conio.h>

#include<string.h>

/* Function to approve leaves*/

void approve_leave() {
    int x, y; /* coordinates */
    FILE * fp; /* file pointer */
    long int recsize = sizeof(e);
    int empid; /* employee id */

    system("cls");
    fp = fopen("EMP.DAT", "rb+");
    if (fp == NULL) {
        fp = fopen("EMP.DAT", "wb+");
        if (fp == NULL) {
            printf("Connot open file");
            exit(1);
        }
    }
    rewind(fp);
    printf("Name\t\t\t\t\tEmployee ID\t Leaves left \t  Balance leaves");
    x = 0, y = 2;
    while (fread( & e, recsize, 1, fp) == 1) {
        if (e.aleaves != 0) {
            gotoxy(x, y);
            puts(e.name);
            x += 40;
            gotoxy(x, y);
            printf("%d", e.id);
            x += 18;
            gotoxy(x, y);
            printf("%d", e.lleaves);
            x += 18;
            gotoxy(x, y);
            printf("%d", e.aleaves);
            y += 2;
            x = 0;
        }
    }
    gotoxy(0, 20);
    printf("Enter the employee id whose leaves to be approved : ");
    scanf("%d", & empid);
    rewind(fp);
    while (fread( & e, recsize, 1, fp) == 1) {
        if (empid == e.id) {
            e.lleaves -= e.aleaves;
            e.aleaves = 0;
            fseek(fp, -recsize, SEEK_CUR);
            fwrite( & e, recsize, 1, fp);
            break;
        }
    }
    fclose(fp);
}
