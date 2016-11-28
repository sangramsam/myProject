#include<stdio.h>
#include<conio.h>
typedef struct node_type
{
int data;
struct node_type *next;
}node;
typedef node *list;
main()
{
list head,temp;
char ch;
int n;
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
while(temp!=NULL)
{
printf("%d\t",temp->data);
temp=temp->next;
}
getch();
}
