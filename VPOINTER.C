#include<stdio.h>
#include<conio.h>
void main()
{
int i=10;
void *v;
v=&i;
//printf("%d",*v);
printf("%d",*(int*)v);
getch();
}
