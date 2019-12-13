#include<stdio.h>

#include"../include/emp_structure.h"

#include"../include/login.h"

#include"../include/console.h"

/* Function to derive user name */

void user_name(int user) {
    gotoxy(70, 0);
    if (user == 1000000) {
        printf("Cristina");
        e.id = user;
    } else {
        printf("%s", e.name);
    }
    gotoxy(70, 1);
    printf("%d", e.id);
}
