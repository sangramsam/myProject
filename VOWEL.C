#include<stdio.h>
#include<conio.h>
void main()
{
char sa[]="itmuniversity";
int i,v=0,k=0;
for(i=0;i<8;i++)
{
if(sa[i]=='a'||sa[i]=='e'||sa[i]=='o'||sa[i]=='i'||sa[i]=='u'||sa[i]=='A'||sa[i]=='E'||sa[i]=='I'||sa[i]=='O'||sa[i]=='U')
{
v++;
}
else
{
k++;
}
}
printf("the no of vowel is=%d",v);
printf("the consonant is=%d",k);
getch();
}

