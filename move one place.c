#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<math.h>
#include<stdlib.h>
int gd=DETECT, gm;

void main()
{
 int R=50,x=200,y=300;
  double ang, area;
  int r;
  void *clear;
initgraph(&gm,&gd,"c:\\tc\\bgi");
  area= imagesize(0,0,150,70);
  clear= malloc(area);
  getimage(0,0,150,70,clear);
  for(ang=8.4;ang>0.0;ang-=(3.14/180))
  {
   setcolor(2);
   setfillstyle(1,62);
   circle(x,y,R);
   floodfill(x,y,2);
   setcolor(0);
   line(x-r*cos(ang),y+r*sin(ang),x+r*cos(ang),y-r*sin(ang));
      delay(10);
  }
 getch();
closegraph();
restorecrtmode();
}

