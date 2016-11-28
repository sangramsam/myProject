#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
void main()
{
int gdriver=DETECT,gmode=0;
initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
line(75,150,175,150);
line(175,150,250,100);
line(250,100,175,100);
line(175,100,140,150);
line(140,150,75,100);
line(75,100,30,100);
line(30,100,75,150);
line(75,100,70,40);
line(70,40,140,100);
line(140,100,140,220);
line(140,100,175,40);
line(175,40,175,100);
arc(140,80,18,180,18);
getch();
}

