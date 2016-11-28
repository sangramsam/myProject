#include<stdio.h>
#include<conio.h>
void main()
{
int a,num;
scanf("%d",num);
a=num%2;
for(;a;)
{
printf("odd");
exit(1);
}
printf("even");
getch();
}