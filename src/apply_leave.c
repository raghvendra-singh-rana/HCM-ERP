#include<stdio.h>

#include"../include/console.h"

#include"../include/emp_structure.h"

#include<stdlib.h>

#include<conio.h>

#include<string.h>

/* function to apply leaves */
/* function is available to employee only*/

void apply_leave(int user) {

    int allowed_leaves = 25; /* allowed leaves */
    int leave; /* actual leaves */
    long int recsize = sizeof(e);
    FILE * fp;

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
    while (fread( & e, recsize, 1, fp) == 1) {

        if (user == e.id) {
            printf("Name :");
            puts(e.name);
            gotoxy(0, 1);
            printf("Employee ID : %d \nEntitled leaves : %d \nLeft Leaves : %d \nPending Approval : %d", e.id, allowed_leaves, e.lleaves, e.aleaves);
            printf("\n\nEnter no of leaves to be applied : ");
            scanf("%d", & leave);
            e.aleaves += leave;
            fseek(fp, -recsize, SEEK_CUR); /* move the cursor 1 step back from current  position */
            fwrite( & e, recsize, 1, fp); /* override the record */
            fflush(stdin);
            printf("\n\nLeave request has been sent to admin for approval");
            getch();
            break;
        }
    }
    fclose(fp);
}
