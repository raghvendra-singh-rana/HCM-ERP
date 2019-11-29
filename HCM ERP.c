#include <stdio.h> ///for input output functions like printf, scanf
#include <stdlib.h>
#include <conio.h>
#include <windows.h> ///for windows related functions (not important)
#include <string.h>  ///string operations



/** List of Global Variable */


/**
    function : gotoxy
    @param input: x and y coordinates
    @param output: moves the cursor in specified position of console
*/

COORD coord = {0,0}; /// top-left corner of window
 FILE *fp, *ft; /// file pointers
    char another, choice;
    char admin[] = {"cristina"}; ///admin
    int user; /// user id
    char pass[10]; ///password
    int curusr; /// current user
    int leave; //No of leaves applied
    int empid; // Employee id
    float whours = 0.00; // No of hours worked
     struct emp e; /// structure variable creation
      struct emp
    {
        char name[40];///name of employee
        int id; // employee id
        char pass[10]; // employee password
        char desig[10]; // employee designation
        int age; /// age of employee
        int leaves; // leaves of employee
        float bs; /// basic salary of employee
        float hours; // no of hours worked
    	int m_id; //Managers ID
    	int lleaves; //No of leaves
    	int aleaves; // applied leaves
    };

    char empname[40]; /// string to store name of the employee

    long int recsize; /// size of each record of employee

    int x = 30; // x coordinate
    int y = 12; //y coordinate
    int tempid = 1000000;
    char tempdesig[10] = "employee";

void gotoxy(int x,int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
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
void add()
{
	file_open();

        system("cls");
             fseek(fp,0,SEEK_END); /// search the file and move cursor to end of the file
            /// here 0 indicates moving 0 distance from the end of the file

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

                printf("\nEnter name: ");
                fgets(e.name, sizeof(e.name), stdin);
                printf("\nEnter Designation: ");
                scanf("%s", &e.desig);

                ///test code below
                if(strcmp(e.desig,tempdesig) !=0)
                {
                    gotoxy(0,10);
                    printf("Please enter valid designation!!!!!!!");
                    getch();

                     break;
                   /* system("cls"); ///clear the console window
                    printf("\nEnter name: ");
                    puts(e.name);
                    printf("\nEnter Designation: ");
                    scanf("%s", &e.desig);
                    */

                }
                /// test code above

                printf("\nEnter age: ");
                scanf("%d", &e.age);
                printf("\nEnter basic salary: ");
                scanf("%f", &e.bs);
                printf("\nEnter password: ");
                scanf("%s",&e.pass);

                /// Adding leaves to 25 by default
                e.lleaves = 25;



               e.hours=0.00;


                fwrite(&e,recsize,1,fp); /// write the record in the file

                printf("\nAdd another record(y/n) ");
                fflush(stdin);
                another = getche();
                fclose(fp);
                //test code below
                system("cls"); ///clear the console window
                //test code above
            }
}

void list(void)
	{
		system("cls");

		file_open(); /// Just to check

            rewind(fp); ///this moves file cursor to start of the file
            printf("Name\t\t\t\t\tAge\tID\t    Salary");
            x=0, y=2;
            while(fread(&e,recsize,1,fp)==1)  /// read the file and fetch the record one record per fetch
            {
                //printf("\n%s\t\t%d %.2f",e.name,e.age,e.bs); /// print the name, age and basic salary
                //for (x = 0,y=2;y<20;y++)

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
                     x += 12;
                    gotoxy(x,y);
                    printf("%d",e.lleaves);

                     x += 12;
                    gotoxy(x,y);
                    printf("%d",e.aleaves);

                           x += 12;
                    gotoxy(x,y);
                    printf("%f",e.hours);
                    ///Please delete above lines of screen

                    x =0;
                    y +=1;
       		}
		getch();
		fclose(fp);
	}

void delete (void)
{
	system("cls");

		file_open();
            another = 'y';
            while(another == 'y')
            {
                printf("\nEnter id of employee to delete: ");
                scanf("%d",&empid);
                ft = fopen("Temp.dat","wb");  /// create a intermediate file for temporary storage
                rewind(fp); /// move record to starting of file
                while(fread(&e,recsize,1,fp) == 1)  /// read all records from file
                {
                    if(empid == e.id) //the entered record match
                    {
                        fwrite(&e,recsize,1,ft); /// move all records except the one that is to be deleted to temp file
                    }
                }
                fclose(fp);
                fclose(ft);
                remove("EMP.DAT"); /// remove the orginal file
                rename("Temp.dat","EMP.DAT"); /// rename the temp file to original file name

                fp = fopen("EMP.DAT", "rb+");
                printf("Delete another record(y/n)");
                fflush(stdin);
                another = getche();
                fclose(fp);
            }
}

void apply_leave(void)
{
	system("cls");

	file_open();
	//
	//printf("%d",user);
	//getche();
	//
	printf("Eneter no of leaves to be applied : ");
	scanf("%d",&leave);
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
                another = getche();
                fclose(fp);

}


void modify()
{
	system("cls");
	file_open();
            another = 'y';
            while(another == 'y')
            {
                printf("Enter the employee id to modify: ");
                scanf("%d", &empid);
                rewind(fp);
                while(fread(&e,recsize,1,fp)==1)  /// fetch all record from file
                {
                    if(empid ==e.id) ///if entered name matches with that in file
                    {
                        printf("\nEnter new name,age and bs: ");
                        scanf("%s%d%f",e.name,&e.age,&e.bs);
                        fseek(fp,-recsize,SEEK_CUR); /// move the cursor 1 step back from current position
                        fwrite(&e,recsize,1,fp); /// override the record
                        break;
                    }
                }
                printf("\nModify another record(y/n)");
                fflush(stdin);
                another = getche();
                fclose(fp);
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

		fclose(fp);
	}

void pay()
	{
		system("cls");
		file_open();
		if (user == 1000000)
		{

			printf("Enter the employee id : ");
			scanf("%d",&empid);
			printf("Do you want to add/modify works hours for employee ? Press y to confirm ");
			choice =getch();
			if ((choice== 'y') || (choice== 'Y'))
			{
					printf("\n\nNo of hours worked: ");
					scanf("%f",&whours);
					rewind(fp);
	                while(fread(&e,recsize,1,fp)==1)  /// fetch all record from file
	                {

	                    if(empid ==e.id) ///if entered name matches with that in file
	                    {
						e.hours = whours;
	                    fseek(fp,-recsize,SEEK_CUR); /// move the cursor 1 step back from current position
                        fwrite(&e,recsize,1,fp); /// override the record
	                    fclose(fp);
	                    break;
	                    }
	                }
			}

		}
		else
		{
			empid = user;

		}

		file_open();
	    while(fread(&e,recsize,1,fp)==1)
		{
printf("%d",e.id);
		 if(empid==e.id)
		 {
		    system("cls");
		    gotoxy(40,5);
		    printf("\"SYSC 5709 F Paystub\" ");
		    getch();
		    gotoxy(2,10);
		    printf("Employee Name: %s",e.name);
		    gotoxy(2,12);
		    printf("Employee ID: %d",e.id);
		    gotoxy(2,14);
		    printf("Number of Hours Worked: %f",e.hours);
		    gotoxy(17,16);
		    printf("Net Pay: %.2f",e.hours*e.bs);
		    gotoxy(15,18);
		    getch();
		}
		fclose(fp);
	}

}

void menu_employee()
{
system("cls"); ///clear the console window
        gotoxy(30,10); /// move the cursor to postion 30, 10 from top-left corner
        printf("1. Apply leaves"); /// option for add record
        gotoxy(30,12);
        printf("2. Display pay stub");
        gotoxy(30,14);
        printf("3. Display Info");
        gotoxy(30,16);
        printf("4. Exit"); ///Approve leaves
        gotoxy(30,22);
        printf("Your Choice: "); /// enter the choice 1, 2, 3, 4, 5
        fflush(stdin); /// flush the input buffer
        choice  = getche(); /// get the input from keyboard
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
		case '4':  /// if user press 3 then do editing existing record
            fclose(fp);  /// close the file
            exit(0); /// exit from the program
	}
}

void menu_admin()
{
	system("cls"); ///clear the console window
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
        choice  = getche(); /// get the input from keyboard
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
                        scanf("%s",&pass);
                        if (strcmp(pass,e.pass) == 0)
                        {
                            system("cls"); ///clear the console window
                            gotoxy(30,10); /// move the cursor to postion 30, 10 from top-left corner
                            printf("*****");
                            gotoxy(30,12);
                            printf("* Welcome ");
                            puts(e.name);
                            gotoxy(30,14); /// move the cursor to postion 30, 10 from top-left corner
                            printf("*****");
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
                        scanf("%s",&pass);
                        if (strcmp(pass,admin) == 0)
                        {
                            system("cls"); ///clear the console window
                            gotoxy(30,10); /// move the cursor to postion 30, 10 from top-left corner
                            printf("*****");
                            gotoxy(30,12);
                            printf("* Welcome Cristina !!!              *");
                            gotoxy(30,14);
                            printf("*****");
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
