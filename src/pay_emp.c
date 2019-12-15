#include<stdio.h>
#include"../include/validate.h"
#include"../include/console.h"
#include"../include/emp_structure.h"
#include"../include/sal_structure.h"
#include"../include/month_convert.h"
#include"../include/user_name.h"
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include"../include/time1.h"

void pay_emp(int user){
    long int recsizes = sizeof(s);
    FILE  *fs;
    fs = fopen("SAL.DAT","r");
    int cmon;
    system("cls");
    printf("\n\nPlease enter the month in digits : ");
    scanf("%d",&cmon);
    rewind(fs);
    while(fread(&s,recsizes,1,fs)==1){
    if((cmon==s.mon) && (s.id==user)){
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
                printf("Month: %d",s.mon);
                gotoxy(15,18);
                printf("Net Pay: %.2f",s.salary);
                getch();


    }
    else{
        printf("salary not generated");
        getch();
    }


}
fclose(fs);
}
