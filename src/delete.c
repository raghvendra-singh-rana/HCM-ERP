#include<stdio.h>
#include"../include/validate.h"
#include"../include/console.h"
#include"../include/emp_structure.h"
#include<stdlib.h>
#include<conio.h>
#include<string.h>


void delete (void){
    /* Variable */
    char another,choice;
    int count;
    int empid; /*Employee id */
    FILE *fp, *ft; /* file pointer */
    long int recsize=sizeof(e); /* size of record */

    system("cls");
    fp = fopen("EMP.DAT","rb+");
        if(fp == NULL){
            fp = fopen("EMP.DAT","wb+");
            if(fp == NULL){
                printf("Connot open file");
                exit(1);
            }
        }
    another = 'y';
    while(another == 'y'){
        printf("%d",e.id);
        system("cls");
        count = 0;
        printf("\nEnter id of employee to delete: ");
        scanf("%d",&empid);
        ft = fopen("Temp.dat","wb");  /* create a intermediate file for temporary storage */
        rewind(fp); /// move record to starting of file
        while(fread(&e,recsize,1,fp) == 1){
            if(empid == e.id){
                count = 1;
                printf("\nRecord found with below details :- \n\nName :");
                puts(e.name);
                printf("Age : %d \nBasic Salary : %f \nDesignation : %s",e.age,e.bs,e.desig);
                printf("\n\nPress 'y' to confirm deletion : ");
                choice = getche();
                if ((choice != 'y')&&(choice !='Y')){
                   fwrite(&e,recsize,1,ft);
                }
            }
            else{
                fwrite(&e,recsize,1,ft); /* move all records except the one that is to be deleted to temp file */
            }
        }
        if (count == 0){
            printf("\nNo record found with ID : %d", empid);
        }
        fclose(fp);
        fclose(ft);
        remove("EMP.DAT"); /* remove the orginal file */
        rename("Temp.dat","EMP.DAT"); /* rename the temp file to original file name */
        fp = fopen("EMP.DAT", "rb+");
        printf("\n\nDelete another record(y/n)");
        fflush(stdin);
        another = getche();
    }
    fclose(fp);
}
