#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
int data;
struct node *next;
struct node *prev;
}*tail=NULL,*head=NULL;
void insertatbeg()
{
int n;
struct node *temp;
printf("enter ur no::\n");
scanf("%d",&n);
temp=(struct node *)malloc(sizeof(struct node));
if(head==NULL||tail==NULL)
{
temp->data=n;
temp->next=NULL;
temp->prev=NULL;
head=tail=NULL;
head=tail=temp;
}
else
{
head->prev=temp;
temp->data=n;
temp->next=head;
temp->prev=NULL;
head=temp;
}
}
void insertatend()
{
int n;
struct node *temp;
printf("enter ur no::\n");
scanf("%d",&n);
temp=(struct node *)malloc(sizeof(struct node));
if(head==NULL||tail==NULL)
{
temp->data=n;
temp->next=NULL;
temp->prev=NULL;
head=tail=NULL;
head=tail=temp;
}
else
{
tail->next=temp;
temp->data=n;
temp->next=NULL;
temp->prev=tail;
tail=temp;
}
}
void insertafter()
{
int n,s;
struct node *temp;
struct node *temp1;
display();
temp=(struct node *)malloc(sizeof(struct node));
printf("after what no you want to insert\n");
scanf("%d",&s);
printf("enter ur no:::\n");
scanf("%d",&n);
temp->data=n;
temp1=head;
while(temp1->data!=s)
{
temp1=temp1->next;
}
temp->prev=temp1;
temp->next=temp1->next;
temp1->next->prev=temp;
temp1->next=temp;
}
void deleteatbeg()
{
struct node *temp;
display();
temp=head->next;
free(head);
temp->prev=NULL;
temp=head;
}
void deleteatend()
{
struct node *temp;
display();
temp=tail->prev;
free(tail);
temp->next=NULL;
}
void deletespec()
{
int n;
struct node *temp;
display();
printf("what no you want to delete\n");
scanf("%d",&n);
temp=head;
while(temp->data!=n)
{
temp=temp->next;
}
temp->prev->next=temp->next;
temp->next->prev=temp->prev;
}
display()
{
struct node *temp;
temp=head;
while(temp!=NULL)
{
printf("%d->",temp->data);
temp=temp->next;
}
printf("\n");
}
void traveseatbeg()
{
struct node *temp;
temp=head;
while(temp!=NULL)
{
printf("%d->",temp->data);
temp=temp->next;
}
}
void traverseatend()
{
struct node *temp;
temp=tail;
while(temp!=NULL)
{
printf("%d->",temp->data);
temp=temp->prev;
}
}
void main()
{
int ch;
printf("--\tDDLimplementation---\n");
clrscr();
do
{
printf("1:insert at begining\n");
printf("2:insert at end\n");
printf("3:insert after node\n");
printf("4:delete at begining\n");
printf("5:delete at end\n");
printf("6:delete  specific node from middle\n");
printf("7:display\n");
printf("8:traverse at begining\n");
printf("9:travese at end\n");
printf("10:EXIT\n");
printf("enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
insertatbeg();
break;
case 2:
insertatend();
break;
case 3:
insertafter();
break;
case 4:
deleteatbeg();
break;
case 5:
deleteatend();
break;
case 6:
deletespec();
break;
case 7:
display();
break;
case 8:
traveseatbeg();
break;
case 9:
traverseatend();
break;
case 10:
break;
}
}
while(ch!=10);
}