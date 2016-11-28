#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct node_type
{
int data;
struct node_type *next;
}node;
typedef node *list;
void insert_at_beg(int value)
{
list temp;
temp=(list)malloc(sizeof(node));
temp->data=value;
if(temp==null)
{
head=temp;
head->next=NULL;
}
else
{
temp->next=head;
head=temp'
}
}
void insert_at_end(int value)
{
list tail,temp;
tail=head;
temp=(list)malloc(sizeof(node));
temp->data=value;
if(head==NULL)
{
head=temp;
head->next=NULL;
}
else
{
while(tail->next!=NULL)
{
tail=tail->next;
}
temp->next=NULL;
tail->next=temp;
}
}
void insert_at_mid(int value,int loc)
{
list temp,temp1;
temp=(list)malloc(sizeof(node));
temp->next=data;
temp1=head;
if(head=NULL)
{
head=temp;
head->next=NULL;
}
else
{
while(temp1->data!=loc)
{
temp1=temp1->next;
}
temp=temp1->next;
temp1->next=temp;
temp->next=temp1;
}
}
void delete_from_middle(int value)
{
list temp,var;
temp=head;
while(temp!=NULL)
{
if(temp->data==value)
{
if(temp==head)
{
head=temp->next;
free(temp);
return 0;
}
else
{
var->next=temp->next;
free(temp);
return 0;
}
}
else
{
var=temp;
temp=temp->next;
}
}
printf("data deleted from list %d",value);
}
int del_from_end()
{
list temp;
temp=head;
while(temp->next!=NULL)
{
var=temp;
temp=temp->next;
}
if(temp==head)
{
head=temp->next;
free(temp);
return 0;
}
 printf("data deleted from list is %d",temp->data);
     var->next=NULL;
     free(temp);
     return 0;
}
void display()
{
list temp;
temp=head;
if(temp==NULL)
{
printf("list is empty\n");
}
else
{
printf("element of list;");
while(temp!=NULL)
{
printf("-----%d",temp->data);
temp=temp-next;
}
printf("\n");
}
}
void main()
{
list head;
head=NULL;
printf("1:INSERT AT BEGNING\n");
printf("2:INSERT AT END \n");
printf("3:INSERT AT MIDDLE WHERE YOU WANT\n");
printf("4:DELETION FROM THE END OF LIST\n");
printf("5:DELETION OF THE DATA WHERE YOU WANT\n");
printf("6:EXIT \n");
while(1)
{
printf("enter the choice \n");
scanf("%d",&i);
switch(i);
{
case 1:
{
int value;
printf("enter the value to insert\n");
scanf("%d",&value);
insert_at_beg(value);
display();
break;
}
case 2:
int value;
printf("enter the value to insert \n");
scanf("%d",&value);
insert_at_end(value);
display();
break;
}
case 3:
                {
                int value,loc;
                printf("after which data you want to insert the data\n");
                scanf("%d",&loc);
                printf("enter the value to be inserted\n");
                scanf("%d",&value);
                insert_at_mid(value,loc);
                display();
                break;
                }
                case 4:
                {
                delete_from_end();
                display();
                break;
                }
                case 5:
                {
                int value;
                display();
                printf("enter the data that you want to delete from the list \n");
                scanf("%d",&value);
                delete_from_mid(value);
                display();
                break;
                }
                case 6:
                {
                exit(0);
                }
           }






