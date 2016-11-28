#include<stdio.h>
#include<conio.h>
void main()
{
//clrscr();
int a[3][3]={1,2,3,4,5,6,7,8,9};
int i,j;
clrscr();
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
if(i>j)
{
printf("0\t");
}
else
{
printf("%d \t",a[i][j]);
}
}
printf("\n");
}
getch();
}
