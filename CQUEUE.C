#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define size 15
struct queue
{
int p[size];
int front;
int rear;
}qe;
int qufull()
{
if(qe.front==0&&qe.rear==size-1||qe.front==qe.rear+1)
{
return 1;
}
else
{
return 0;
}
}
void quinsert(int item)
{
qe.p[qe.rear]=item;
qe.rear++;
}
void display()
{
int i;
for(i=qe.front;i<qe.rear;i++)
{
printf("%d\t",qe.p[i]);
}
}
int qedelete()
{
int item;
item=qe.p[qe.front];
qe.front++;
if(qe.front==qe.rear)
{
qe.rear=0;
}
return(item);
}
/*int stempty()
{
if(qe.rear==0||qe.front==0)
{
return (1);
}
else
{
return (0);
}
}*/
void main()
{
int item,i,choice;
char ans;
qe.rear=0;
qe.front=0;
do
{
printf("implementing circular queues\n");
printf("1.insert\n");
printf("2.delete\n");
printf("3.display\n");
printf("4.exit\n");
printf("enetr your choice\n");
scanf("%d",&choice);
switch(choice)
{
case 1:
clrscr();
if(qufull())
{
printf("queue is full\n");
}
else
{
printf("enter ur no\n");
scanf("%d",&item);
quinsert(item);
}
break;
case 2:
/*if(stempty())
{
printf("queue is empty\n");
}
else
{ */
item=qedelete();
printf("deleted element is=%d\n",item);
break;
case 3:
display();
break;
case 4:
exit(0);
break;
}
printf("do you want to continue\n");
ans=getche();
}
while(ans=='y'||ans=='Y');
getch();
}