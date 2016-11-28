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
qe.rear=0;
qe.p[qe.rear]=item;
qe.rear++;
if(qe.rear==size-1)
{
qe.rear=0;
}
}
/*void display()
{
int i;
for(i=qe.front;i<qe.rear;i++)
{
sleep(1);
printf("%d\t",qe.p[i]);
//qe.front++;
}
}*/
int delete()
{
int item;
item=qe.p[qe.front];
qe.front++;
return(item);
}
int empty()
{
if(qe.rear==0||qe.front==0)
{
return (1);
}
else
{
return (0);
}
}
void main()
{
int item,n,i;
qe.rear=0;
qe.front=0;
clrscr();
printf("how many no you want to insert\n");
scanf("%d",&n);
//scanf("%d",&item);
if(qufull())
{
printf("queue is full\n");
}
else
{
printf("enter ur no\n");
for(i=0;i<n;i++)
{
scanf("%d",&item);
quinsert(item);
}
}
printf("data inserted\n");
//display();
if(empty())
{
printf("empty queue\n");
}
else
{
item=delete();
printf("\ndelete element is=%d\n",item);
}
//display();
getch();
}