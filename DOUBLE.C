#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
int data;
struct node *next;
struct node *prev;
}*head,*tail;
void main()
{
char ch;
struct node *temp;
int n;
head=tail=NULL;
clrscr();
do
{
printf("\nenter ur no:\n");
scanf("%d",&n);
temp=(struct node *)malloc(sizeof(struct node));
if(head==NULL)
{
temp->data=n;
temp->next=NULL;
temp->prev=NULL;
head=temp;
tail=head;
}
else
{
tail->next=temp;
temp->data=n;
temp->next=NULL;
temp->prev=tail;
tail=temp;
}
printf("enter more data (y/n)\n");
ch=getche();
}
while(ch=='y'||ch=='Y');
printf("data inserted\n");
printf("traverse at begining\n");
temp=head;
while(temp!=NULL)
{
printf("%d ",temp->data);
temp=temp->next;
}
/*printf("traverse at end\n");
temp=tail;
while(temp!=NULL)
{
printf("%d ",temp->data);
temp=temp->prev;
}*/

printf("delete node at begining\n");
//struct node *temp;
temp=head->next;
free(head);
temp->prev=NULL;
head=temp;
printf("traverse at begining\n");
temp=head;
while(temp!=NULL)
{
printf("%d ",temp->data);
temp=temp->next;
}
/*printf("traverse at end\n");
temp=tail;
while(temp!=NULL)
{
printf("%d ",temp->data);
temp=temp->prev;
}*/
printf("delete node at end\n");
temp=tail->prev;
free(tail);
temp->next=NULL;
tail=temp;
printf("traverse at begining\n");
temp=head;
while(temp!=NULL)
{
printf("%d ",temp->data);
temp=temp->next;
}
getch();
}



