#include<stdio.h>
#include<conio.h>
#include"../include/test_run_validate.h"
#include"../include/test_run_login.h"
#include"../include/test_run_delete.h"
#include"../include/test_run_new_pass.h"
int main(){

    test_run_new_pass(1000001);
getch();
printf("\n");
printf("-----------------------------------------------------------");
    delete(1000001);
getch();
printf("\n");
printf("\n-----------------------------------------------------------");
printf("\n");
printf("\n-----------------------------------------------------------");
    int result;
    result =test_run_validate();
    if (result == 1){
        printf("\nTested case passed");
    }
    else{
        printf("\nTest case failed");
    }
getch();
printf("\n");
printf("-----------------------------------------------------------");
  test_run_login();
printf("\n");
printf("-----------------------------------------------------------");
getch();
getch();
return 0;
}
