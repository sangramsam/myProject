#include<stdio.h>
#include<conio.h>
void main()
{
int m1[3][3]={2,4,1,3,4,2,6,7,3},m2[3][3]={4,6,3,2,3,1,4,3,2},m[4][4];
int c,d,e,s;
clrscr();
for(c=0;c<3;c++)
{
for(d=0;d<3;d++)
{ s=0;
for(e=0;e<3;e++)
s=s+m1[c][e]*m2[e][d];
m[c][d]=s;
}
} gotoxy(5,3);
printf("\n\n\tMultiplying two matirx...");sleep(2);
printf("\n\n\tMatrix m1..... Matrix m2.....\n");
for(c=0;c<3;c++)
{ printf("\n\t");
for(d=0;d<3;d++)
printf("%d ",m1[c][d]);
printf("\t\t\t");
for(d=0;d<3;d++)
printf("%d ",m2[c][d]);
printf("\n");
}
printf("\n\tNow Matrix m after multiplying matirx m1 and m2...\n");
for(c=0;c<3;c++)
{ printf("\n\t\t\t");
for(d=0;d<3;d++)
printf("%d ",m[c][d]);
printf("\n");
}
getch();
}