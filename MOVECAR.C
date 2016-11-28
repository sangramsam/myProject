#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<math.h>
#include<stdlib.h>
int gd=DETECT, gm;
void main()
{
 int R=15,x=40,y=400;
 double ang, area;
 int r,x1;
 void *clear;
initgraph(&gm,&gd,"c:\\turboc3\\bgi");
  		area= imagesize(0,0,150,70);
  		clear= malloc(area);
  		getimage(0,0,150,70,clear);
  		delay(1900);
  		for(ang=8.4;ang>0.0;ang-=(3.14/180))
  		{
   		putimage(x-40,350,clear,0);
   		x1=x+75;
   		setcolor(2);
   		setfillstyle(1,62);
   		circle(x,y,R);
   		circle(x1,y,R);
   		floodfill(x,y,2);
  		floodfill(x1,y,2);
   		setcolor(0);
   		r=R-2;
   		line(x-r*cos(ang),y+r*sin(ang),x+r*cos(ang),y-r*sin(ang));
   		line(x1-r*cos(ang),y+r*sin(ang),x1+r*cos(ang),y-r*sin(ang));
   		x++;
   		setcolor(4);
   		arc(x,y,0,180,R+1);
   		arc(x1,y,0,180,R+1);
   		line(x+17,y,x1-17,y);
   		line(x-26,y,x-17,y);
   		line(x1+17,y,x1+26,y);
   		arc(x,y,90,180,R+11);
   		arc(x1,y,0,90,R+11);
   		line(x,y-(R+11),x,y-(R+15));
   		line(x1,y-(R+11),x1,y-(R+15));
   		arc(x+15,y-(R+15),90,180,15);
  		arc(x1-15,y-(R+15),0,90,15);
   		line(x+15,y-(R+30),x1-15,y-(R+30));
   		delay(50);
  		}
 		getch();
closegraph();
restorecrtmode();
}     

