#include<stdio.h>
#include"../include/validate.h"
#include"../include/console.h"
#include"../include/emp_structure.h"
#include"../include/sal_structure.h"
#include"../include/month_convert.h"
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include"../include/time1.h"


void pay(int user){
    long int recsize = sizeof(e);
    long int recsizes = sizeof(s);
    FILE *fp, *fs;
    int count;
    int cmon;
    int month;
    int empid;
    float whours;
    int choice;
    char *smon;

    system("cls");
    user_name(user);
    month=time1();

    fp = fopen("EMP.DAT","rb+");
    if(fp == NULL){
        fp = fopen("EMP.DAT","wb+");
        if(fp == NULL){
            printf("Connot open file");
            exit(1);
        }
    }
    /* open salary file */
    fs = fopen("SAL.DAT","rb+");
    if(fs == NULL){
        fs = fopen("SAL.DAT","wb+");
        if(fs == NULL){
            printf("Connot open file");
            exit(1);
        }
    }
    gotoxy(7,0);
    if (user == 1000000){
        printf("Enter the employee id : ");
        scanf("%d",&empid);
        rewind(fp);
        while(fread(&e,recsize,1,fp)==1){
            if(empid == e.id){
                count=1;
                printf("\n\nPlease enter the month in digits : ");
                scanf("%d",&cmon);
                if((cmon<1) || (cmon>month)){
                        printf("\nInvalid Month. Going back to main menu");
                        getch();
                        return;
                }
            rewind(fs);
            while(fread(&s,recsizes,1,fs)==1){
                if((empid == s.id) && (cmon == s.mon)){
                    printf("\nSalary already generated for this month.");
                    count =2;
                    getch();
                    break;
                }
            }

            if (count != 2){
                printf("\nDo you want to add works hours for employee ? Press y to confirm ");
                choice =getche();
                if ((choice== 'y') || (choice== 'Y')){
                    printf("\n\nNo of hours worked: ");
                    scanf("%f",&whours);
                    s.id = empid;
                    strcpy(s.name,e.name);
                    s.mon = cmon;
                    s.hours = whours;
                    s.salary = whours * e.bs;
                    fwrite(&s,recsizes,1,fs);
                    smon=month_convert(cmon);
                    printf("\n\nSalary aaded for %d for month %s!",e.id,smon);
                    getch();
                    break;
                }
                else{
                return;
                }

            }
            }
        }

        if (count ==0){
            printf("\nInvalid employee id. Going back to main menu");
            getch();
            return;
        }
    }
    else{
        empid = user;
        printf("User ID : %d",user);
        printf("\n\nPlease enter the month in digits : ");
        scanf("%d",&cmon);
        if((cmon<1) || (cmon>month)){
            printf("\nInvalid Month. Going back to main menu");
            getch();
            return;
        }
    }

    rewind(fs);
    while(fread(&s,recsizes,1,fs)==1){
        if((empid==s.id) &&(s.mon == cmon)){
            count =1;
            system("cls");
            gotoxy(40,5);
            printf("\"SYSC 5709 F Paystub\" ");
            gotoxy(2,10);
            printf("Employee Name: %s",s.name);
            gotoxy(2,12);
            printf("Employee ID: %d",s.id);
            gotoxy(2,14);
            printf("Number of Hours Worked: %f",s.hours);
            gotoxy(17,16);
            smon = month_convert(cmon);
            printf("Month: %s",smon);
            gotoxy(15,18);
            printf("Net Pay: %.2f",s.salary);
            getch();
        }

    }
    if (count != 1){
        printf("Your salary is not generated, Please get in touch with admin");
        getch();
    }
    fclose(fp);
    fclose(fs);
}
