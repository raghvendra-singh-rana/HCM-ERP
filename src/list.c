#include<stdio.h>
#include"../include/EMP_STRUCTURE.H"
#include"../include/console.h"
#include<stdlib.h>
#include<conio.h>

void list(void)
{
system("cls");
FILE * fp;
              fp = fopen("EMP.DAT", "rb+");
  if (fp == NULL) {
    fp = fopen("EMP.DAT", "wb+");
    if (fp == NULL) {
      printf("Connot open file");
      exit(1);
    }
  }
int x = 30; // x coordinate
    int y = 12; //y coordinate
long int recsize = sizeof(e);
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