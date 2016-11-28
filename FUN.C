#include<stdio.h>
#include<conio.h>
void main()
{
printf("we are in main fun\n");
int add();
int c;
c=add();
printf("%d",c);
getch();
}
int add()
{
int a,b;
printf("enter \n");
scanf("%d%d",&a &b);
return(a+b);
}
