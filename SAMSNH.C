#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
char snh[]="sangramsnh";
int i;
for(i=0;snh[i]=='\0';i++)
{
snh[i]=snh[i]+32;
}
printf("%s",snh);
getch();
}