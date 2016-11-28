#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
#include<math.h>
const float pi=3.14;
int gd=DETECT, gm;
double size;
int i,x,y;
void *buf;
void main()
{
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
line(250,200,100,200);
line(250,190,100,190);
line(100,100,150,100);
line(150,100,150,150);
line(100,100,100,200);
line(100,120,150,120);
line(150,150,250,150);
line(220,120,220,150);
line(210,120,210,150);
circle(215,120,5);
circle(215,120,3);
circle(215,120,1);
line(250,150,250,200);
line(240,150,250,200);
circle(250,210,10);
circle(200,210,10);
circle(150,210,10);
circle(100,210,10);
circle(250,210,5);
circle(250,210,3);
circle(250,210,1);
circle(200,210,3);
circle(200,210,1);
circle(150,210,3);
circle(150,210,1);
circle(100,210,5);
circle(100,210,3);
circle(100,210,1);
circle(215,100,4);
circle(210,90,4);
circle(205,80,3);
circle(200,70,2);
outtextxy(90,110,"  Train");
line(0,220,260,220);
 size=imagesize(50,50,300,300);
 buf=(char *)malloc(size);
 getimage(50,50,300,300,buf);

 for(i=0;i<=360;i+=5)
// sound(2430);
 {
 cleardevice();
x=150*cos(i*pi/180);
y=150*sin(i*pi/180);
putimage(250+x,100-y,buf,0);

// putimage(i,50,buf,0);
 delay(100);
 }
// nosound();
getch();
restorecrtmode();
}




