#include<stdio.h>
#include<conio.h>
#include<malloc.h>
typedef struct node_type
{
int data;
struct node_type *next;
}node;
typedef node *list;
main()
{
list head,temp,ptr;
char ch;
int n,choice;
head=NULL;
clrscr();
printf("enter data ?(y/n) \n");
ch=getche();
fflush(stdin);
while(ch=='y'||ch=='Y')
{
printf("give data:");
scanf("%d",&n);
temp=(list)malloc(sizeof(node));
temp->data=n;
temp->next=head;
head=temp;
printf("enter more data ? (y/n) \n");
scanf("\n%c",&ch);
fflush(stdin);
}
temp=head;
while(temp->next!=NULL)
{
printf("%d->",temp->data);
temp=temp->next;
}
printf("\n");
printf("=========================\n");
printf("deletion of last node\n");
temp=head;
ptr=head;
while(temp->next!=NULL)
{
ptr=temp;
temp=temp->next;
}
ptr->next=NULL;
free(temp);
printf("element deleted\n");
temp=head;
while(temp->next!=NULL)
{
printf("%d->",temp->data);
temp=temp->next;
}
printf("deletion of specific node\n");
printf("enter your choice to delete\n");
scanf("%d",&choice);
temp=head;
ptr=head;
while(temp->data!=choice)
{
ptr=temp;
temp=temp->next;
}
ptr->next=temp->next;
free(temp);
printf("element deleted\n");
temp=head;
while(temp->next!=NULL)
{
printf("%d->",temp->data);
temp=temp->next;
}
printf("\n\n");
printf("deletion of first node\n");
temp=head;
head=temp->next;
free(temp);
temp=head;
while(temp->next!=NULL)
{
printf("%d->",temp->data);
temp=temp->next;
}


getch();
}
