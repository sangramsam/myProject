#include<stdio.h>
#include<conio.h>
int even(int a)
{
if(a%2==0)
{
return(1);
}
else
{
return(0);
}
}
void main()
{
//int even(int x);
if(even(4))
{
printf("no is even\n");
}
else
{
printf("no is odd\n");
}
getch();
}