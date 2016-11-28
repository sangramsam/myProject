#include<graphics.h>
#include<stdio.h>
#include<conio.h>
void main()
{
int gd=DETECT, gm;
initgraph(&gd, &gm,"c:\\tc\\bgi");
setcolor(8);
moveto(250,200);
lineto(350,350);
moveto(450,200);
lineto(350,350);
line(250,200,450,200);
line(450,300,250,300);
moveto(350,150);
lineto(250,300);
moveto(450,300);
lineto(350,150);
getch();
restorecrtmode();
}