#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
const float PI=3.14159;
void main()
{
int x,y;
int i;
int gd, gm;
gd=DETECT;

initgraph(&gd,&gm,"c:\\turbootc\\bgi");
setcolor(6);
circle(270,250,200);
circle(270,250,180);
circle(270,250,35);
circle(270,250,25);
for(i=0;i<=360;i+=15);
{
x=180*cos(i*PI/200);
y=180*sin(i*PI/200);
line(270,250,270+x,250-y);
}
{
x=180*cos(i*PI/560);
y=180*sin(i*PI/560);
line(270,250,270+x,250-y);
}
{
x=180*cos(i*PI/320);
y=180*sin(i*PI/320);
line(270,250,270+x,250-y);
}

getch();
restorecrtmode();
}