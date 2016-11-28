#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
char ch[]="india";
char ch1[]="is";
char ch2[]="country";
char ch3[19];
clrscr();
strcat(ch,ch1);
strcat(ch1,ch2);
strcpy(ch3,ch);
strcpy(ch3,ch3);
printf("%s",ch);
printf("%s",ch1);
printf("%s",ch2);
printf("\n");
printf("%s",ch3);
getch();
}
