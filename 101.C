#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
int b[]={2,3,4,0,-3,-4,-8};
int sump=0,sumn=0,i,sum=0;
for(i=0;i<=6;i++)
{
if(b[i]<0)
{
sumn=sumn+b[i];
}
else if(b[i]>0)
{
sump=sump+b[i];
}
else
{
}
}
for(i=0;i<=6;i++)
{
sum=sum+b[i];
}


printf("the average is=%d\n",sum/7);
printf("%d\n",sumn);
printf("%d\n",sump);
getch();
}




