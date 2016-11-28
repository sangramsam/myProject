#include<stdio.h>
#include<conio.h>
void main()
{
int front=0,rear=0,i,n;
int arr[5];
clrscr();
do
{
printf("enter your no\n");
scanf("%d",&n);
arr[rear]=n;
rear++;
}
while(rear<5);
printf("no inserted\n");
/*for(i=top;i>=0;i--)
{
printf("%d",arr[i]);
}*/
n=arr[front];
front=front-1;
printf("deleted=%d",n);
getch();
}






