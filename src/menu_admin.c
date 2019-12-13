#include"../include/add.h"

#include"../include/list.h"

#include"../include/modify.h"

#include"../include/delete.h"

#include"../include/approve_leave.h"

#include"../include/pay.h"

#include"../include/console.h"

#include<stdio.h>

#include<stdlib.h>

/* Admin's Menu */

void menu_admin(int user) {
    /* clear the console window */
    char choice;

    user = 1000000;

    while (choice != '7') {
        system("cls");
        user_name(user);
        time1();
        gotoxy(30, 5);
        printf("Admin's Menu'");
        gotoxy(30, 10); /* move the cursor to postion 30, 10 from top-left corner */
        printf("1. Add Record"); /* option for add record */
        gotoxy(30, 12);
        printf("2. List Records"); /* option for showing existing record */
        gotoxy(30, 14);
        printf("3. Modify Records"); /* option for editing record */
        gotoxy(30, 16);
        printf("4. Delete Records"); /* option for deleting record */
        gotoxy(30, 18);
        printf("5. Approve leaves"); /* Approve leaves */
        gotoxy(30, 20);
        printf("6. Check Pay"); /* pay stub */
        gotoxy(30, 22);
        printf("7. Exit"); /* Exit */
        gotoxy(30, 24);
        printf("Your Choice: "); /* Enter the choice 1, 2, 3, 4, 5 */
        fflush(stdin); /* flush the input buffer */
        scanf("%c", & choice);
        switch (choice) {
        case '1':
            add();
            break;
        case '2':
            list();
            break;
        case '3':
            modify();
            break;
        case '4':
            delete();
            break;
        case '5':
            approve_leave();
            break;
        case '6':
            pay(user);
            break;
        case '7':
            break;
            exit(0); /* exit from the program */
        }
    }
}
