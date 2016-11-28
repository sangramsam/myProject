#include<stdio.h>
#include<conio.h>
struct node
{
int data;
struct node *next;
}*top=NULL;
void push();
void pop();
void traverse();
void main()
{
int ch;
clrscr();
do
{
printf("\n main menu");
printf("\n 1.push");
printf("\n 2.pop");
printf("\n 3.traverse");
printf("\n 4.exit");
printf("\n enter ur choice");
scanf("%d",&ch);
switch(ch)
{
case 1:
push();
break;
case 2:
pop();
break;
case 3:
traverse();
break;
}
}
while(ch!=4);
}
void push()
{
int item;
struct node *tmp;
tmp=(struct node*)malloc(sizeof(struct node));
printf("enter ur item\n");
scanf("%d",&item);
tmp->data=item;
tmp->next=top;
top=tmp;
}
void pop()
{
struct node *tmp;
if(top==NULL)
{
printf("\n stack is underflow");
}
else
{
tmp=top;
printf("\n element deleted is=%d",tmp->data);
top=top->next;
free(tmp);
}
}
void traverse()
{
if(top==NULL)
{
printf("\n stack is underflow");
}
else
{
struct node *tmp;
tmp=top;
while(tmp!=NULL)
{
printf("%d ",tmp->data);
tmp=tmp->next;
}
}
}















