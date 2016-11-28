#include<graphics.h>
#include<stdio.h>
#include<conio.h>
void main()
{
int gd=DETECT,gm;
int i;
initgraph(&gd,&gm,"c:\\tc\\bgi");
for(i=0;i<200;i+=25)
{
circle(250,250,i);
}
getch();
restorecrtmode();
}