#include<stdio.h>

#include"../include/console.h"

#include"../include/emp_structure.h"

#include<stdlib.h>

#include<conio.h>

#include<string.h>

#include<time.h>

/* Function to get time, month, date and year */

int time1(void) {
    int hours, minutes, seconds, day, month, year;
    time_t now; /* time_t is arithmetic time type */
    time( & now); /* Obtain current time */
    struct tm * local = localtime( & now); /* structure for time */
    hours = local - > tm_hour; /* get hours since midnight (0-23) */
    minutes = local - > tm_min; /* get minutes passed after the hour (0-59) */
    seconds = local - > tm_sec; /* get seconds passed after the minute (0-59) */
    day = local - > tm_mday; /* get day of month (1 to 31) */
    month = local - > tm_mon + 1; /*  get month of year (0 to 11) */
    year = local - > tm_year + 1900; /* get year since 1900 */
    /* print local time */
    gotoxy(70, 3);
    if (hours < 12) /* before midday */
        printf("%02d:%02d:%02d am\n", hours, minutes, seconds);
    else /* after midday */
        printf("%02d:%02d:%02d pm\n", hours - 12, minutes, seconds);
    gotoxy(70, 2);
    /* print current date */
    printf("%02d/%02d/%d\n", day, month, year);
    return month;
}
