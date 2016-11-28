#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
main()
{
int a[100],i,temp,j,n;
clrscr();
printf("-----program of sorting----\n");
printf("how many number you want to insert\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("data inserted\n");
for(i=0;i<n;i++)
{
for(j=i+1;j<=n;j++)
{
if(a[i]<a[j])
{
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
}
printf("sorting perform\n");
for(i=0;i<n;i++)
{
sleep(2);
printf("%d \t",a[i]);
}
exit(0);
getch();
}