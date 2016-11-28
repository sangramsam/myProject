#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<stdio.h>
class screen
{
 public :
 void floor(int x, int y)
 {
  setcolor(BLUE);
  rectangle(x,y,getmaxx()/2-10,y+12);
  setfillstyle(1,1);
  floodfill(x+1,y+1,1);
  setcolor(WHITE);
 }
 void lift(int x, int y,int c)
 {
  setcolor(c);
  rectangle(x,y,x+6,y+12);
  setfillstyle(1,c);
  floodfill(x+1,y+1,c);
 }
 void state_0()
 {
  screen obj;
  obj.lift(600,380,63);
  obj.lift(600,400,63);
  obj.lift(600,420,63);
  obj.lift(600,440,63);
  obj.lift(600,460,63);
  setcolor(0);
  outtextxy(600,384,"4");
  outtextxy(600,404,"3");
  outtextxy(600,424,"2");
  outtextxy(600,444,"1");
  outtextxy(600,464,"0");
  }
 void operate(int y1, int y2)
 {
  void *image,*clear;
  int area;
  int start,end,floor;
  screen obj;
  start=getmaxy()-12-(117*y1);
  if(y1==4)
	start=1;
  end=getmaxy()-12-(117*y2);
  area=imagesize(getmaxx()/2-9,start,getmaxx()/2-3,start+12);
  image=malloc(area);
  getimage(getmaxx()/2-9,start,getmaxx()/2-3,start+12,image);
  area=imagesize(0,13,6,25);
  clear=malloc(area);
  getimage(0,13,6,25,clear);
  if(y2>y1)
  {
   while(start>end+1&&start>1)
   {
    floor=-1;
    putimage(getmaxx()/2-9,start,clear,0);
    start--;
    if(start>=2&&start<14) floor=4;
    if(start>=117&&start<129)floor=3;
    if(start>=234&&start<246)floor=2;
    if(start>=351&&start<363)floor=1;
    if(start>=468&&start<480)floor=0;
    putimage(getmaxx()/2-9,start,image,0);
    obj.state_0();
    if(floor>=0)
     obj.lift(600,460-20*floor,62);
    delay(50);
   }
  }
  if(y2<y1)
  {
   while(start<end-1)
   {
    floor=-1;
    if(start+10>=0&&start<12) floor=4;
    if(start+10>=117&&start<129)floor=3;
    if(start+10>=234&&start<246)floor=2;
    if(start+10>=351&&start<363)floor=1;
    if(start+10>=468&&start<480)floor=0;
    putimage(getmaxx()/2-9,start,clear,0);
    start++;
    putimage(getmaxx()/2-9,start,image,0);
    obj.state_0();
    if(floor>=0)
     obj.lift(600,460-20*floor,62);
    delay(50);
   }
  }
 }
};

void main()
{
int gd= DETECT, gm;
int y1=0,y2;
char ch;
initgraph(&gd,&gm,"c:\\tc\\bgi");
screen obj;
obj.floor(2,0);
outtextxy(100,4,"FORTH FLOOR");
obj.floor(0,117);
outtextxy(100,121,"THIRD FLOOR");
obj.floor(0,234);
outtextxy(100,237,"SECOND FLOOR");
obj.floor(0,351);
outtextxy(100,354,"FIRST FLOOR");
obj.floor(0,468);
outtextxy(100,472,"GROUND FLOOR");
obj.lift(getmaxx()/2-9,getmaxy()-12,62);
obj.state_0();
obj.lift(600,460-y1,62);
while(1)
{
 if(kbhit())
 {
  ch= getch();
  if(ch=='\r')
   break;
   y2=(int)ch-48;
  if(y2<0||y2>4)
   continue;
  else
  {
   obj.operate(y1,y2);
   y1=y2;
  }
 }
}
closegraph();
restorecrtmode();
}
