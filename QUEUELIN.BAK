#include<stdio.h>
#include<conio.h>
#include<malloc.h>
typedef struct node_type
{
int data;
struct node_type *next;
}node;
typedef node *list;
list rear=NULL,front=NULL;
void insert();
void delet();
void traverse();
void main()
{
int n;
do
{
printf("\n");
printf("1.insert\n");
printf("2.delete\n");
printf("3.traverse\n");
printf("4.exit\n");
printf("enter your choice\n");
scanf("%d",&n);
switch(n)
{
case 1:
insert();
break;
case 2:
delet();
break;
case 3:
traverse();
break;
case 4:
break;
}
}
while(n!=4);
getch();
}
void insert()
{
int item;
list temp;
printf("enter the element \n");
scanf("%d",&item);
if(rear==NULL || front==NULL)
{
temp=(list)malloc(sizeof(node));
temp->data=item;
temp->next=rear;
rear=temp;
front=rear;
}
else
{
temp=(list)malloc(sizeof(node));
temp->data=item;
temp->next=rear;
rear=temp;
}
}
void delet()
{
list temp,temp1;
if(rear==NULL)
{
printf("queue underflow\n");
}
else if(front==rear)
{
printf("deleted element is=%d",rear->data);
rear=NULL;
front==NULL;
}
else
{
temp=rear;
while(temp->next!=front)
{
temp=temp->next;
}
temp1=temp;
printf("deleted element is->%d",front->data);
temp1->next=NULL;
free(front);
front=temp1;
}
}
void traverse()
{
list temp;
if(rear==NULL)
{
printf("queue underflow\n");
}
temp=rear;
while(temp!=NULL)
{
printf("%d->",temp->data);
temp=temp->next;
}
}
