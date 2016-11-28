#include<stdio.h>
#include<conio.h>
void main()
{
char sa[]="sangram";
int i,v,k;
for(i=0;i<8;i++)
{
if(sa[i]=='a'||sa[i]=='e'||sa[i]=='o'||sa[i]=='i'||sa[i]=='u')
{
v++;
}
else
{
c++;
}
}
printf("the no of vowel is=%d",v);
printf("the consonant is=%d",c);
getch();
}

