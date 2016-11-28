#include<stdio.h>
#include<conio.h>
struct employ
{
char empname[6];
char empdestin[10];
int salary;
int t;
};
void main()
{
int i=20,j=9;
int k;
struct employ e[3];
clrscr();
for(k=0;k<3;k++)
{
printf("enter the name \n");
scanf("%s",e[k].empname);
printf("employ destin\n");
scanf("%s",e[k].empdestin);
printf("enter the salary\n");
scanf("%d",&e[k].salary);
}
clrscr();
gotoxy(i,j);
printf("NAME        DESTIN         SALARY               T.A \n");
gotoxy(i,j+1);
printf("--------------------------------------------------");
j=13;
for(k=0;k<3;k++)
{
//fflush(stdin);
gotoxy(i,j+k);
if(e[k].empdestin=="mngr");
{
e[k].t=e[k].salary-e[k].salary*25/100;
printf("%s",e[k].empname);
printf("       %s",e[k].empdestin);
printf("             %d",e[k].salary);
printf("                 %d",e[k].t);
}
if(e[k].empdestin=="stmngr")
{
e[k].t=e[k].salary-e[k].salary*15/100;
printf("%s",e[k].empname);
printf("     %s",e[k].empdestin);
printf("             %d",e[k].salary);
printf("               %d",e[k].t);
}
if(e[k].empdestin=="clerk")
{
e[k].t=e[k].salary-e[k].salary*5/100;
printf("%s",e[k].empname);
printf("     %s",e[k].empdestin);
printf("             %d",e[k].salary);
printf("                 %d",e[k].t);
}
}
getch();
}

