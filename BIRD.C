#include<graphics.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
void main()
{   int gd=DETECT,gm,i,j,p,q,x,y,k,flag;
  struct arccoordstype arcinfo;
  initgraph(&gd,&gm,"c:\\turboc3\\bgi");
  y=getmaxy()/2;
  i=0;   p=0;   q=0;   j=0;
  flag=0;
  setcolor(YELLOW);
  for(k=0;k<500;k++)
putpixel(random(620),random(419),15);
  while(!kbhit())
  {  line(0+i,y+20,0+i,y-20);  
  line(0+i,y+20,20+i,y);
  line(0+i,y-20,20+i,y);
  ellipse(80+i,y,10-p,350+p,50,10);
  ellipse(80+i,y,10-p,350+p,40,10);
  ellipse(80+i,y,10-p,350+p,30,10);
  ellipse(80+i,y,10-p,350+p,20,10);
  ellipse(80+i,y,10-p,350+p,10,10);
  line(130+i,y-12,130+i,y+1);
  line(125+i,y-20,125+i,y-5);
  line(135+i,y-18,140+i,y-5);
  line(35+i,y+15,55+i,y+10);
  line(40+i,y+20,55+i,y+10);
  if(flag==0)
  p=p+2;
  if(flag==1)
  p=p-2;
  circle(130+i,y-18,6);
  circle(130+i,y-18,1);
  line(60+i,y-25,30+i,y-45+j);
  line(30+i,y-45+j,100+i,y-25);
  line(60+i,y+25,30+i,y+45+q);
  line(30+i,y+45+q,100+i,y+25);
  i=i+3;
  if(i>=638)     i=0;
  if(flag==0)    j=j-2,q=q+2;
  if(flag==1)     j=j+2,q=q-2;
  if(j<=-10)      flag=1;
  else if(j>=0)     flag=0;
  delay(100);    cleardevice();  }
  getch();
  closegraph();
 }

