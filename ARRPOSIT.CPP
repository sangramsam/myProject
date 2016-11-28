#include<stdio.h>
#include<conio.h>
void main()
{
int a[5],i,psum=0,nsum=0;
printf("enter the array element");
for(i=0;i<5;i++)
{
scanf("%d",&a[i]);
}
for(i=0;i<5;i++)
{
if(a[i]>0)
{
psum=psum+a[i];
}
else
{
nsum=nsum+a[i];
}
}
printf("sum of +ve sum numbers=%d\n",psum);
printf("sum of -ve sum numbers=%d\n",nsum);
getch();
}
