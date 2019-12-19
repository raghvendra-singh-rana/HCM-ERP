/**
 * @file Console.c
 * @brief This file contains definition of
 *        funtion to move the cursor to specific position       
 *        on the screen   
 */
#include<windows.h>

COORD coord = {0,0};
void gotoxy(int x, int y) {
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
