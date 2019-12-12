#include"../include/login.h"
#include"../include/add.h"
#include<stdio.h>
#include"../include/list.h"
#include"../include/modify.h"
#include"../include/delete.h"
#include"../include/apply_leave.h"
#include"../include/approve_leave.h"
#include"../include/info.h"
#include"../include/pay.h"
#include"../include/menu_employee.h"
#include<stdlib.h>

int main(void){
    /* variables */
    int choice; /* option */
    int user; /* User id */

    /* login screen */
    user =login();
    time1();
    /* Menu for admin */
    if(user == 1000000){
        system("cls");
        menu_admin(user);
    }

    /* Menu for employee */
    else{
        system("cls");
        menu_employee(user);
    }

    /* exit from program */
    return 0;
}
