#include<stdio.h>
#include<conio.h>
void main()
{
int a[10],i,n;
printf("given n:");
scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%d",a+i);
printf("\n numbers read are:");
for(i=0;i<n;i++)
printf("%d",*(a+i));
printf("\n");
getch();
}