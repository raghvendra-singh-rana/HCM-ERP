#include<stdio.h>

#include"../include/validate.h"

#include"../include/console.h"

#include"../include/user_name.h"

#include"../include/emp_structure.h"

#include"../include/apply_leave.h"

#include"../include/info.h"

#include"../include/new_pass.h"

#include"../include/pay.h"

#include"../include/pay_emp.h"

#include<stdlib.h>

#include<conio.h>

#include<string.h>

/* Employee's Menu*/
void menu_employee(int user) {
    char choice;
    while (1) {
        system("cls"); /* clear the console window */
        user_name(user); /* logged on user info */
        gotoxy(30, 5);
        printf("Employee's Menu'");
        gotoxy(30, 10); /*  move the cursor to postion 30, 10 from top-left corner */
        printf("1. Apply leaves"); /* option for add record */
        gotoxy(30, 12);
        printf("2. Display pay stub"); /* Display pay stub */
        gotoxy(30, 14);
        printf("3. Display Info"); /* Display employee information */
        gotoxy(30, 16);
        printf("4. Change Password"); /* Change password */
        gotoxy(30, 18);
        printf("5. Exit"); /* Exit */
        gotoxy(30, 22);
        printf("Your Choice: ");
        fflush(stdin); /* flush the input buffer */
        scanf("%c", & choice);
        switch (choice) {
        case '1':
            printf("%d",user);
            apply_leave(user);
            break;
        case '2':
            printf("%d",user);
            pay_emp(user);
            break;
        case '3':
            printf("%d",user);
            info(user);
            break;
        case '4':
            printf("%d",user);
            new_pass(user);
            break;
        case '5':
            exit(0); /*  exit from the program */
        }
    }
}
