#include<stdio.h>
#include<conio.h>
struct snh
{
int rollno;
char name[10];
char add[20];
};
void main()
{
clrscr();
int i,n;
struct snh p[5];
for(i=0;i<5;i++)
{
printf("enetr ur rollno\n");
scanf("%d",&p[i].rollno);
printf("enter ur name\n");
scanf("%s",p[i].name);
printf("enter ur adrss\n");
scanf("%s",p[i].add);
}
printf("data inserted\n");
printf("----------------\n");
printf("-----SEARCH------\n");
printf("enter ur roll no\n");
scanf("%d",&n);
for(i=0;i<5;i++)
{
if(p[i].rollno==n)
{
printf("rollno is=%d\n",p[i].rollno);
printf("name is=%s\n",p[i].name);
printf("addres is=%s\n",p[i].add);
}
}
getch();
}




