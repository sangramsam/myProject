#include<stdio.h>
#include<conio.h>
void main()
{
int n,n1,c,j,k;
j=0;
k=1;
scanf("%d",&n);
for(c=0;c<n;c++)
{
if(c<=1)
n1=c;
else
{
n1=j+k;
j=k;
k=n1;
}
printf("%d\n",n1);
}
getch();
}