#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
const float PI=3.14154;
void main()
{
int gdriver=DETECT,gmode=0;
int I;
int x,y;
initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
cleardevice();
rectangle(0,0,639,479);
outtextxy(250,20,"INDIAN FLAG");
rectangle(80,50,560,380);
line(80,160,560,160);
line(80,270,560,270);
setfillstyle(SOLID_FILL,LIGHTRED);
floodfill(85,60,getmaxcolor());
setfillstyle(SOLID_FILL,WHITE);
floodfill(85,170,getmaxcolor());
setfillstyle(SOLID_FILL,GREEN);
floodfill(85,280,getmaxcolor());
setcolor(BLUE);
circle(320,215,50);
for(I=0;I<=360;I+=15)
{
x=50*cos(I*PI/180);
y=50*sin(I*PI/180);
line(320,215,320+x,215-y);
}
setcolor(CYAN);
settextstyle(TRIPLEX_FONT,HORIZ_DIR,6);
outtextxy(200,400,"    JAI HIND!!!" ) ;
getch();
}
