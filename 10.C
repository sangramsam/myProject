#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
int a[]={1,2,0,4,5,-3,0};
int sump=0,sumn=0,i,sum=0;
for(i=0;i<=6;i++)
{
if(a[i]<0)
{
sumn=sumn+a[i];
}
else if(a[i]>0)
{
sump=sump+a[i];
}
else
{
}
}
for(i=0;i<=6;i++)
{
sum=sum+a[i];
}
printf("the average is=%d\n",sum/7);
printf("%d\n",sumn);
printf("%d\n",sump);
getch();
}




