/*
Authors : Abhinandan Sharma(Kya bolu?) & Raghvendra Singh Rana(101123931)
Date    : 03-Dec-2019
Program : HCM - ERP : Employee Management System
*/

#include <stdio.h> ///for input output functions like printf, scanf
#include <stdlib.h> //Standard i/o lib
#include <conio.h>
#include <windows.h> ///for windows related functions (not important)
#include <string.h>  ///string operations
#include <time.h>



/** List of Global Variable */


/*
    function : gotoxy
    @param input: x and y coordinates
    @param output: moves the cursor in specified position of console
*/

COORD coord = {0,0}; /// top-left corner of window
 FILE *fp, *ft, *fs; /// file pointers
    char another, choice;
    char admin[] = {"cristina"}; ///admin
    int user; /// user id
    //char pass[10]; ///password
    char pass[] = {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0',}; /// password
    char npass[] = {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0',}; /// new password
    char c; /// character
    int curusr; /// current user
    int leave; //No of leaves applied
    int empid; // Employee id
    float whours = 0.00; // No of hours worked
    struct emp e; /// structure variable creation
    int allowed_leaves = 25; // Allowed leaves
    char error = 0; // error code
    char tname[40]; /// Temprary name
    int count = 0; /// Matching record for particular ID
    int i;
    int cmon;
    char *smon;
    int hours, minutes, seconds, day, month, year;

    struct emp
    {
        char name[40];///name of employee
        int id; // employee id
        char pass[10]; // employee password
        char desig[10]; // employee designation
        int age; /// age of employee
        int leaves; // leaves of employee
        float bs; /// basic salary of employee
        //float hours; // no of hours worked
    //int m_id; //Managers ID
    int lleaves; //No of leaves
    int aleaves; // applied leaves
    };

    struct sal
    {
        int id;
        char name[40];
        float hours;
        int mon;
        float salary;
    };
    struct sal s;

    // for time


    char empname[40]; /// string to store name of the employee

    long int recsize; /// size of each record of employee
    long int recsizes = sizeof(s); /// size of record of salary file

    int x = 30; // x coordinate
    int y = 12; //y coordinate
    int tempid = 1000000;
    //char tempdesig[10] = "employee";
    char tempdesig[2][10] = {"employee","manager"};

void gotoxy(int x,int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

/// Function to validate employee details.
int validate()
{
    if (e.name == ' ')
    {
        gotoxy(0,20);
        printf("Please enter valid employee name");
        getch();
        return 1;
    }

                /// Validate designation
    if((strcmp(e.desig,tempdesig) !=0) && (strcmp(e.desig,tempdesig +1) !=0))
    {
        gotoxy(0,20);
        printf("Please enter valid designation!");
        getch();
        return 1;
    }
                /// Validate age
    if ((e.age < 18) || (e.age >120))
    {
        gotoxy(0,20);
        printf("Please enter valid age");
        getch();
        return 1;
    }
}
// fuction to add employee

/** Main function started */

void file_open()
{
fp = fopen("EMP.DAT","rb+");
    if(fp == NULL)
    {
        fp = fopen("EMP.DAT","wb+");
        if(fp == NULL)
        {
            printf("Connot open file");
            exit(1);
        }
    }
}

void file_opens()
{
fs = fopen("SAL.DAT","rb+");
    if(fs == NULL)
    {
        fs = fopen("SAL.DAT","wb+");
        if(fs == NULL)
        {
            printf("Connot open file");
            exit(1);
        }
    }
}




//Function to derive time
void time1 (void)
{


// time_t is arithmetic time type
time_t now;

// Obtain current time
// time() returns the current time of the system as a time_t value
time(&now);

//gotoxy(70,4);
// Convert to local time format and print to stdout
//printf("%s", ctime(&now));

// localtime converts a time_t value to calendar time and returns a pointer
// to a tm structure with its members filled with the corresponding values
struct tm *local = localtime(&now);

hours = local->tm_hour; // get hours since midnight (0-23)
minutes = local->tm_min; // get minutes passed after the hour (0-59)
seconds = local->tm_sec; // get seconds passed after the minute (0-59)

day = local->tm_mday; // get day of month (1 to 31)
month = local->tm_mon + 1; // get month of year (0 to 11)
year = local->tm_year + 1900; // get year since 1900

// print local time
gotoxy(70,3);
if (hours < 12) // before midday
printf("%02d:%02d:%02d am\n", hours, minutes, seconds);
else // after midday
printf("%02d:%02d:%02d pm\n", hours - 12, minutes, seconds);

gotoxy(70,2);
// print current date
printf("%02d/%02d/%d\n", day, month, year);

}

void user_name()
{
gotoxy(70,0);
if (user == 1000000)
printf("Cristina");
else
printf("%s",e.name);

gotoxy(70,1);
printf("%d",user);

time1();

}


void month_convert(int cmon)
{
switch (cmon)
{

case 1: smon = "Jan";
break;

case 2: smon = "Feb";
break;

case 3: smon = "Mar";
break;

case 4: smon = "Apr";
break;

case 5: smon = "May";
break;

case 6: smon = "Jun";
break;

case 7: smon = "Jul";
break;

case 8: smon = "Aug";
break;

case 9: smon = "Sep";
break;

case 10: smon = "Oct";
break;

case 11: smon = "Nov";
break;

case 12: smon = "Dec";
break;
}
}

/// Add functionality
void add()
{
file_open();

        system("cls");
        user_name();
             fseek(fp,0,SEEK_END); /// search the file and move cursor to end of the file
            /// here 0 indicates moving 0 distance from the end of the file
            //gotoxy(0,20);
            //printf("Press # to return to previous menu");
            //choice = getche();
            //if (choice == '#')
              //  return;
            gotoxy(30,0);
            printf("Add Menu");
            gotoxy(0,6);
            another = 'y';
            while(another == 'y')  /// if user want to add another record
            {

                /// test code below
                rewind(fp); ///this moves file cursor to start of the file
                    while(fread(&e,recsize,1,fp)==1)  /// read the file and fetch the record one record per fetch
                    {
                        tempid = e.id; /// store last employee id
                    }
                e.id = tempid + 1;
                //fclose(fp);
                /// test code above
//getch();
//gotoxy(2,2);
                printf("Enter name: ");
                scanf("%s",e.name);
                fflush(stdout);
                fgets(tname, sizeof(e.name), stdin);
                strcat(e.name,tname);
                //scanf("%s",&e.name);
                //fflush(stdout);
                //fgets(e.name, sizeof(e.name), stdin);
                //gets(sizeof(e.name));
                //gets(e.name);
                //printf("\n%s",e.name);
                //printf("%s\n",e.name);
                //gotoxy(2,4);
                printf("\nEnter Designation(%s,%s): ",tempdesig,tempdesig + 1);
                scanf("%s", &e.desig);


/*
                if((strcmp(e.desig,tempdesig) !=0) && (strcmp(e.desig,tempdesig +1) !=0))
                {
                    gotoxy(0,10);
                    printf("Please enter valid designation!!!!!!!");
                    getch();
                    // just checkinf below code
add();
//just checking abov code
                    break;
                   /* system("cls"); ///clear the console window
                    printf("\nEnter name: ");
                    (e.name);
                    printf("\nEnter Designation: ");
                    scanf("%s", &e.desig);
                    */

     //           }

                /// test code above

                printf("\nEnter age: ");
                scanf("%d", &e.age);
                printf("\nEnter basic salary: ");
                scanf("%f", &e.bs);
                printf("\nEnter password: ");
                scanf("%s",&e.pass);

                /// Adding leaves to 25 by default
                e.lleaves = allowed_leaves;



                //e.hours=0.00;

                /// Validate name
                error = validate();
                //printf("\n%d",error);
                if (error == 1)
                {
                    break;
                }

//printf("Are you sure to enter this record");
printf("\n\nPlease press 'Y' to enter record of %d : ",e.id);
//scanf("%c",&choice);

choice = getche();
if ((choice == 'y') ||(choice == 'Y'))
{
fwrite(&e,recsize,1,fp); /// write the record in the file
}
//else
//{
// e.reset();
//}

                printf("\n\nDo you want to add another record(y/n) ");
                fflush(stdin);
                another = getche();
                //fclose(fp);
                //test code below
                system("cls"); ///clear the console window
                //test code above
                //*

            }
            fclose(fp);
}
///
void list(void)
{
system("cls");

            file_open();
            rewind(fp); ///this moves file cursor to start of the file
            printf("Name\t\t\t\t\tAge\tID\t    Hourly wage\t  Leaves left\t Applied leaves");
            x=0, y=2;
            while(fread(&e,recsize,1,fp)==1)  /// read the file and fetch the record one record per fetch
            {
                    gotoxy(x,y);
                    puts(e.name);
                    x +=40;
                    gotoxy(x,y);
                    printf("%d",e.age);
                    x += 8;
                    gotoxy(x,y);
                    printf("%d",e.id);
                    x += 12;
                    gotoxy(x,y);
                    printf("%.2f",e.bs);

                    //Please mdelete below linesa of code
                    x += 14;
                    gotoxy(x,y);
                    printf("%d",e.lleaves);

                     x += 15;
                    gotoxy(x,y);
                    printf("%d",e.aleaves);

                    x =0;
                    y +=1;

        }

fclose(fp);
getch();
}

void delete (void)
{
system("cls");

file_open();
            another = 'y';
            while(another == 'y')
            {
                system("cls");
                count = 0;
                printf("\nEnter id of employee to delete: ");
                scanf("%d",&empid);
                ft = fopen("Temp.dat","wb");  /// create a intermediate file for temporary storage
                rewind(fp); /// move record to starting of file
                while(fread(&e,recsize,1,fp) == 1)  /// read all records from file
                {
                    if(empid == e.id) //the entered record match
                    {
                        count = 1;
                        printf("\nRecord found with below details :- \n\nName :");
                        puts(e.name);
                        printf("Age : %d \nBasic Salary : %f \nDesignation : %s",e.age,e.bs,e.desig);
                        //printf("\nEnter new name,age and bs: ");
                        //gotoxy(0,10);
                        printf("\n\nPlease press 'y' to confirm deletion : ");
                        choice = getche();
                        if ((choice != 'y')&&(choice !='Y'))
                        {

                           fwrite(&e,recsize,1,ft);
                        }
                    }
                    else
                    {
                        fwrite(&e,recsize,1,ft); /// move all records except the one that is to be deleted to temp file
                    }
                }
                if (count == 0)
                    {
                        printf("\nNo record found with ID : %d", empid);
                    }
                fclose(fp);
                fclose(ft);
                remove("EMP.DAT"); /// remove the orginal file
                rename("Temp.dat","EMP.DAT"); /// rename the temp file to original file name

                fp = fopen("EMP.DAT", "rb+");
                printf("\n\nDelete another record(y/n)");
                fflush(stdin);
                another = getche();

            }
            fclose(fp);
}

void apply_leave(void)
{
system("cls");


//
//printf("%d",user);
//getche();
//
printf("Name :");
    puts(e.name);
    gotoxy(0,1);
    printf("Employee ID : %d \nEntitled leaves : %d \nLeft Leaves : %d \nPending Approval : %d",e.id,allowed_leaves,e.lleaves,e.aleaves);
printf("\n\nEnter no of leaves to be applied : ");
scanf("%d",&leave);
file_open();
rewind(fp);
                while(fread(&e,recsize,1,fp)==1)  /// fetch all record from file
                {
                    if(user == e.id) ///if entered name matches with that in file
                    {
                        //printf("Record matched!!");
                        e.aleaves += leave;
fseek(fp,-recsize,SEEK_CUR); /// move the cursor 1 step back from current position
                        fwrite(&e,recsize,1,fp); /// override the record
                        break;
                    }
                }
                fflush(stdin);
                printf("\n\nLeave request has been sent to admin for approval");
                getch();
                //another = getche();
                fclose(fp);

}


void modify()
{
system("cls");
file_open();
            another = 'y';
            while(another == 'y')
            {
                system("cls");
                printf("Enter the employee id to modify: ");
                scanf("%d", &empid);
                count = 0;
                file_open();
                rewind(fp);
                while(fread(&e,recsize,1,fp)==1)  /// fetch all record from file
                {

                    if(empid ==e.id) ///if entered name matches with that in file
                    {
                        count = 1;
                        printf("\nRecord found with below details :- \n\nName :");
                        puts(e.name);
                        printf("Age : %d \nBasic Salary : %f \nDesignation : %s",e.age,e.bs,e.desig);
                        //printf("\nRecord found with below details :- \nName : %s\nAge : %d \nBasic Salary : %f \nDesignation : %s",e.name,e.age,e.bs,e.desig);
                        //printf("\nEnter new name,age and bs: ");
                        //gotoxy(0,10);
                        printf("\n\nPlease enter new details :- \n\nName : ");
                        //close(stdin);
                        scanf("%s",e.name);
                        fflush(stdout);
                        fgets(tname, sizeof(e.name), stdin);
                        strcat(e.name,tname);
                        //sscanf(&e.name);
                        //scanf("%[^\n]%*c", &e.name);
                        //gotoxy(0,12);
                        printf("\nEnter Designation(%s,%s): ",tempdesig,tempdesig + 1);
                        scanf("%s", &e.desig);
                        printf("\nEnter age: ");
                        scanf("%d", &e.age);
                        printf("\nEnter basic salary: ");
                        scanf("%f", &e.bs);
                        error = validate();
                        if (error == 1)
                        {
                            break;
                        }
                        //scanf("%s%d%f",e.name,&e.age,&e.bs);
                        printf("\nPlease press Y to confirm");
                        choice = getche();
                        if ((choice == 'y')||(choice == 'Y'))
                        {
                            fseek(fp,-recsize,SEEK_CUR); /// move the cursor 1 step back from current position
                            fwrite(&e,recsize,1,fp); /// override the record
                            break;
                        }

                    }

                }
                if (count == 0)
                    {
                        printf("\n\nNo record found with ID : %d",empid);
                    }
                printf("\n\nModify another record(y/n)");
                empid = 0;
                fflush(stdin);
                another = getche();
                fclose(fp);
            }
            fclose(fp);
}
void new_pass()
{
system("cls");
        printf("Hello %sPlease enter your old password : ",e.name);
        for (i=0;i<10;i++)
        {
            c=getch();
            if ((c== 13) ||(c == 10)||(c == 32))
            {
                break;
            }
            pass[i] = c;
            printf("*");
            }

        if (strcmp(e.pass,pass) == 0)
        {
            for(i=0;i<=10;i++)
            {
               pass[i] = '\0';
            }

            printf("\nPlease enter your new password :");

            for (i=0;i<10;i++)
            {
                c=getch();
                if ((c== 13) ||(c == 10)||(c == 32))
                {
                    break;
                }
                pass[i] = c;
                printf("*");
            }

            printf("\nPlease re-enter your new password");
            for (i=0;i<10;i++)
            {
            c=getch();
            if ((c== 13) ||(c == 10)||(c == 32))
            {
                break;
            }
            npass[i] = c;
            printf("*");

            }

        if (strcmp(pass,npass) == 0)
        {
            file_open();
            rewind(fp);
            while(fread(&e,recsize,1,fp)==1)  /// fetch all record from file
            {
                if(e.id == user)
                {
                    strcpy(e.pass,npass);
                    fseek(fp,-recsize,SEEK_CUR); /// move the cursor 1 step back from current position
                    fwrite(&e,recsize,1,fp);
                    printf("\n\nPassword successfully chnaged");
                    getch();
                    break;
                }
            }
            fclose(fp);
        }
        else
        {
            printf("\nNew passwords are not matching");
            getch();
        }
        }
        else
        {
            printf("\nWrong old password");
            getch();
        }
}

void approve_leave()
{
system("cls");
file_open();
rewind(fp);

printf("Name\t\t\t\t\tEmployee ID\t Leaves left \t  Balance leaves");
x=0, y=2;


               while(fread(&e,recsize,1,fp)==1)  /// fetch all record from file
               {

                   if(e.aleaves != 0) ///if entered name matches with that in file
                   {
///


gotoxy(x,y);
                   puts(e.name);
                   x +=40;
                   gotoxy(x,y);
                   printf("%d",e.id);
                   x += 18;
                   gotoxy(x,y);
                   printf("%d",e.lleaves);
                   x += 18;
                   gotoxy(x,y);
                   printf("%d",e.aleaves);

                   y+=2;
                   x=0;

///
                   }
               }

gotoxy(0,20);
printf("Enter the employee id whose leaves to be approved : ");
scanf("%d",&empid);
rewind(fp);
   while(fread(&e,recsize,1,fp)==1)  /// fetch all record from file
       {
       if(empid ==e.id) ///if entered name matches with that in file
           {
e.lleaves -= e.aleaves;
e.aleaves =0;
               fseek(fp,-recsize,SEEK_CUR); /// move the cursor 1 step back from current position
                    fwrite(&e,recsize,1,fp); /// override the record
               fclose(fp);
               break;
           }
    }

fclose(fp);
}

void info()
{
system("cls");
file_open();
        rewind(fp); /// move record to starting of file
        while(fread(&e,recsize,1,fp) == 1)  /// read all records from file
        {
            if(user == e.id) //the entered record match
            {
                printf("Name :");
        puts(e.name);
        gotoxy(0,1);
        printf("Employee ID : %d \nAge : %d \nDesignation : %s \nBasic Salary: %.2f",e.id,e.age,e.desig,e.bs);
        getch();
            }
}
fclose(fp);
}

void pay()
{
system("cls");
file_open();
file_opens();
if (user == 1000000)
{

printf("Enter the employee id : ");
scanf("%d",&empid);
rewind(fp);
while(fread(&e,recsize,1,fp)==1)
{
if(empid == e.id)
{
count=1;
printf("\n\nPlease enter the month in digits : ");
scanf("%d",&cmon);
//if ((cmon < 1)||(cmon >12))
if((cmon<1) || (cmon>month))
                    {
                        printf("\nInvalid Month. Going back to main menu");
                        getch();
                        return;
                    }
rewind(fs);
                    while(fread(&s,recsizes,1,fs)==1)
                    {
                        if((empid == s.id) && (cmon == s.mon))
                        {
                            printf("\nSalary already generated for this month.");
                            count =2;
getch();
break;
                        }


           }

if (count != 2)
{
printf("\nDo you want to add works hours for employee ? Press y to confirm ");
choice =getche();
if ((choice== 'y') || (choice== 'Y'))
{
printf("\n\nNo of hours worked: ");
scanf("%f",&whours);
s.id = empid;
                       strcpy(s.name,e.name);
                       s.mon = cmon;
                           s.hours = whours;
                           s.salary = whours * e.bs;
                           fwrite(&s,recsizes,1,fs); /// override the record
month_convert(cmon);
                           printf("\n\nSalary aaded for %d for month %s!",e.id,smon);
                           getch();
                           break;

                   }
                   else
                   {
                    return;
                   }

}



}

}

if (count ==0)
{
printf("\nInvalid employee id. Going back to main menu");
getch();
return;
}
}
else
{
empid = user;
printf("\n%d",user);
printf("\n\nPlease enter the month in digits : ");
scanf("%d",&cmon);
//if ((cmon < 1)||(cmon >12))
if((cmon<1) || (cmon>month))
            {
                printf("\nInvalid Month. Going back to main menu");
                getch();
                return;
            }
}

rewind(fs);
   while(fread(&s,recsizes,1,fs)==1)
{
if((empid==s.id) &&(s.mon == cmon))
{
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
   month_convert(cmon);
   printf("Month: %s",smon);
   gotoxy(15,18);
   printf("Net Pay: %.2f",s.salary);
   getch();
}

}
if (count != 1)
    {
        printf("Your salary is not generated, Please get in touch with admin");
        getch();
    }
    fclose(fp);
    fclose(fs);
}

void menu_employee()
{
system("cls"); ///clear the console window
user_name();
gotoxy(30,5);
printf("Employee's Menu'");
        gotoxy(30,10); /// move the cursor to postion 30, 10 from top-left corner
        printf("1. Apply leaves"); /// option for add record
        gotoxy(30,12);
        printf("2. Display pay stub");
        gotoxy(30,14);
        printf("3. Display Info");
        gotoxy(30,16);
        printf("4. Change Password"); ///Change password
        gotoxy(30,18);
        printf("5. Exit"); ///Change password
        gotoxy(30,22);
        printf("Your Choice: "); /// enter the choice 1, 2, 3, 4, 5
        fflush(stdin); /// flush the input buffer
        //choice  = getche(); /// get the input from keyboard
        choice = getche();
switch(choice)
        {
        case '1':  /// if user press 1
            apply_leave();
            break;
        case '2':
            pay();
            break;
        case '3':
            info();
            break;
        case '4':
            new_pass();
            break;
case '5':  /// if user press 3 then do editing existing record
            fclose(fp);  /// close the file
            exit(0); /// exit from the program
}
}

void menu_admin()
{
system("cls"); ///clear the console window
gotoxy(30,5);
printf("Admin's Menu'");
        gotoxy(30,10); /// move the cursor to postion 30, 10 from top-left corner
        printf("1. Add Record"); /// option for add record
        gotoxy(30,12);
        printf("2. List Records"); /// option for showing existing record
        gotoxy(30,14);
        printf("3. Modify Records"); /// option for editing record
        gotoxy(30,16);
        printf("4. Delete Records"); /// option for deleting record
        gotoxy(30,18);
        printf("5. Approve leaves"); ///Approve leaves
        gotoxy(30,20);
        printf("6. Check Pay"); ///Approve leaves
        gotoxy(30,22);
        printf("7. Exit"); ///Approve leaves
        gotoxy(30,24);
        printf("Your Choice: "); /// enter the choice 1, 2, 3, 4, 5
        fflush(stdin); /// flush the input buffer
        //choice  = getche(); /// get the input from keyboard
        //choice = getche();
        scanf("%c",&choice);
switch(choice)
        {
        case '1':  /// if user press 1
            add();
            break;
        case '2':
            list();
            break;
case '3':  /// if user press 3 then do editing existing record
            modify();
            break;
        case '4':
            delete();
            break;
        case  '5':
        approve_leave();
        break;
        case  '6':
        pay();
        break;
case '7':
            fclose(fp);  /// close the file
            exit(0); /// exit from the program
}
}




int main()
{

    /** structure that represent a employee */




    /** open the file in binary read and write mode
    * if the file EMP.DAT already exists then it open that file in read write mode
    * if the file doesn't exit it simply create a new copy
    */
    file_open();

    /// sizeo of each record i.e. size of structure variable e
    recsize = sizeof(e);

    /// Logic to login into the application
        system("cls"); ///clear the console window
        gotoxy(30,10); /// move the cursor to postion 30, 10 from top-left corner
        printf("Please enter your user id: "); /// option for add record
        scanf("%d",&user);
        rewind(fp); /// move record to starting of file
            while(fread(&e,recsize,1,fp) == 1)  /// read all records from file
                {
                    if(user == e.id)  /// if the entered record match
                    {
                        gotoxy(30,12);
                        printf("Please enter your password :");
                        for (i=0;i<10;i++)
                        {
                            c=getch();
                            if ((c== 13) ||(c == 10)||(c == 32))
                            {
                                break;
                            }
                            pass[i] = c;
                            printf("*");
                        }

                        if (strcmp(pass,e.pass) == 0)
                        {
                            system("cls"); ///clear the console window
                            gotoxy(30,10); /// move the cursor to postion 30, 10 from top-left corner
                            printf("***********************");
                            gotoxy(30,12);
                            printf("* Welcome ");
                            puts(e.name);
                            gotoxy(30,14); /// move the cursor to postion 30, 10 from top-left corner
                            printf("***********************");
                            curusr = e.id;
                            getch();
                            break;
                        }
                        else
                            {
                                gotoxy(30,20);
                                printf("Wrong password!");
                                getch();
                                exit(0);
                            }

                    }


                }
                if(user == 1000000)
                    {
                        gotoxy(30,12);
                        printf("Please enter your password :");

                        /// logic for password encryption
                        for (i=0;i<10;i++)
                        {
                            c=getch();
                            if ((c== 13) ||(c == 10)||(c == 32))
                            {
                                break;
                            }
                            pass[i] = c;
                            printf("*");
                        }

                        if (strcmp(admin,pass) == 0)
                        {
                            system("cls"); ///clear the console window
                            gotoxy(30,10); /// move the cursor to postion 30, 10 from top-left corner
                            printf("*************************************");
                            gotoxy(30,12);
                            printf("* Welcome Cristina !!!              *");
                            gotoxy(30,14);
                            printf("*************************************");
                            getche();
                            curusr = 1000000;
                        }
                        else
                            {
                                gotoxy(30,20);
                                printf("Wrong password");
                                getch();
                                exit(0);
                            }
                    }
                    else if(curusr < 1000000)
                    {
                        gotoxy(30,20);
                        printf("Wrong User!");
                        getch();
                        exit(0);
                    }
        fclose(fp);
    /// Login logic end

    /// infinite loop continues untile the break statement encounter
    while(1)
    {
      if (user == 1000000)
  menu_admin();
 else
  menu_employee();
    }
    return 0;
}

