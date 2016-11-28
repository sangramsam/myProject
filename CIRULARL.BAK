#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
int data;
struct node *next;
}*head=NULL,*tail=NULL;
void insert_at_begin();
void insert_at_end();
void delete_at_begin();
void delete_at_end();
void delete_at_specific_node();
void in_order_traverse();
void main()
{
int ch;
clrscr();
do
{
printf("MAIN MENU\n");
printf("[1].insert_at_begin\n");
printf("[2].insert_at_end\n");
printf("[3].delete_at_begin\n");
printf("[4].delete_at_end\n");
printf("[5].delete_at_specific_node\n");
printf("[6].in_order_traverse\n");
printf("[7].exit\n");
printf("enter ur choice");
scanf("%d",&ch);
switch(ch)
{
case 1:
insert_at_begin();
break;
case 2:
insert_at_end();
break;
case 3:
delete_at_begin();
break;
case 4:
delete_at_end();
break;
case 5:
delete_at_specific_node();
break;
case 6:
in_order_traverse();
break;
case 7:
break;
}
}
while(ch!=7);
}
void insert_at_begin()
{
int i,n,m;
struct node *temp;
printf("how many no u want to enter\n");
scanf("%d",&m);
printf("enter ur no");
for(i=0;i<m;i++)
{
scanf("%d",&n);
temp=(struct node *)malloc(sizeof(struct node));
temp->data=n;
if(head==NULL)
{
tail=head=temp;
temp->next=head;
}
else
{
temp->next=head;
tail->next=temp;
head=temp;
}
}
}
void insert_at_end()
{
int i,n,m;
struct node *temp;
printf("how many no u want to enter\n");
scanf("%d",&m);
printf("enter ur no");
for(i=0;i<m;i++)
{
scanf("%d",&n);
temp=(struct node *)malloc(sizeof(struct node));
temp->data=n;
if(head==NULL)
{
head=tail=temp;
temp->next=head;
}
else
{
tail->next=temp;
temp->next=head;
tail=temp;
}
}
}
void delete_at_begin()
{
struct node *temp;
temp=head->next;
tail->next=temp;
free(head);
head=temp;
}
void delete_at_end()
{
struct node *temp,*ptr;
if(head==NULL)
{
printf("list is underflow");
}
else
{
ptr=temp=head;
while(temp->next!=head)
{
ptr=temp;
temp=temp->next;
}
ptr->next=tail->next;
tail=ptr;
free(temp);
}
}
void delete_at_specific_node()
{
int s;
struct node *temp,*ptr;
temp=head;
printf("what no u want to delete");
scanf("%d",&s);
while(temp->data!=s)
{
ptr=temp;
temp=temp->next;
}
ptr->next=temp->next;
free(temp);
}
void in_order_traverse()
{
struct node *temp;
if(head==NULL)
{
printf("list is underlow");
}
else
{
temp=head;
while(temp->next!=head)
{
printf("%d->",temp->data);
temp=temp->next;
}
}
}

