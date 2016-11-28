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
main()
{
list temp,head;
int n,i,l,sum=0,c=0;
head=NULL;
clrscr();
printf("how many no you want to enter\n");
scanf("%d",&l);
for(i=0;i<l;i++)
{
printf("\ngive data:");
scanf("%d",&n);
temp=(list)malloc(sizeof(node));
temp->data=n;
temp->next=head;
head=temp;
}
temp=head;
while(temp!=NULL)
{
sum=sum+temp->data;
c++;
temp=temp->next;
}
printf("%d",sum/c);
getch();
}
