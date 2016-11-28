#include<stdio.h>
#include<conio.h>
void main()
{
int a[5];
clrscr();
printf("a=%u\n",a);
printf("a+1=%u\n",a+1);
printf("a+2=%u\n",a+2);
printf("a+9=%u\n",a+9);

a[2]=6;
a[9]=7;
printf("*(a+2)=%d a[2]=%d\n\n",*(a+2),a[2]);
printf("*(a+9)=%d a[9]=%d\n\n",*(a+9),a[9]);

getch();
}