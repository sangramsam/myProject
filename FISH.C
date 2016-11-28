#include<graphics.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
#include<stdio.h>

void main()
{
  int gd=DETECT,gm,i,j,p,q,x,y,k,flag;
  struct arccoordstype arcinfo;
  initgraph(&gd,&gm,"c:\\turboc3\\bgi");
  y=getmaxy()/2;
  i=0;
  p=0;
  q=0;
  j=0;
  flag=0;
  setcolor(WHITE);
  for(k=0;k<500;k++)
    putpixel(random(620),random(419),15);
  while(!kbhit())
  {
  line(0+i,y+20,0+i,y-20);  /*triangle*/
  line(0+i,y+20,20+i,y);
  line(0+i,y-20,20+i,y);

  ellipse(80+i,y,10-p,350+p,60,25);
  ellipse(80+i,y,10-p,350+p,60,30);

  line(140+i,y+3,130+i,y+8);
  line(130+i,y+8,140+i,y-5);

  if(flag==0)
  p=p+2;
  if(flag==1)
  p=p-2;

  circle(120+i,y-6,5);
  arc(80+i,y,10-i,130,12);   //moving circle
  arc(80+i,y,10-i,130,10);
  arc(80+i,y,10-i,130,8);
	    /* for fin */
 //line(60+i,y-25,30+i,y-45+j);
 // line(30+i,y-45+j,100+i,y-25);
 // line(60+i,y+25,30+i,y+45+q);
 // line(30+i,y+45+q,100+i,y+25);
   line(70+i,y+25,30+i,y+15+q);
  i=i+3;
  if(i>=638)
   i=0;

  if(flag==0)
  j=j-2,q=q+2;

  if(flag==1)
  j=j+2,q=q-2;

  if(j<=-10)
  flag=1;
  else if(j>=0)
  flag=0;

  delay(100);
  cleardevice();
  }
  getch();
  closegraph();
  getch();
}

