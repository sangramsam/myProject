#include<stdio.h>
#include<conio.h>
#include<malloc.h>
typedef struct node_type
{
int data;
struct node_type *next;
}node;
typedef node *list;
list head;
create_list(int dat)
{
list head,temp,tail;
temp=(list)malloc(sizeof(node));
temp->data=dat;
temp->next=NULL;
if(head==NULL)
{
head=temp;
}
else
{
tail=(list)malloc(sizeof(node));
while(tail!=NULL)
tail=tail->next;
tail->next=temp;
}
}
addatbeg(int dat)
{
list temp;
temp=(list)malloc(sizeof(node));
temp->data=dat;
temp->next=head;
temp=head;
}
addafter(int dat,int p)
{
list temp,h;
int i;
h=head;
for(i=0;i<p-1;i++)
{
h=h->next;
if(h===NULL)
{
printf("no insert\n");
exit(1);
}
}
temp=(list)malloc(sizeof(node));
temp->next=h->next;
temp->data=dat;
h->next=temp;
}
}
display(int start)
{
while(start!=NULL)
{
printf("%d",start->data);
start=start->next;
}
printf("\n");
}



main()
{
int choice,n,m,position,i;
char ans;
//list head;
{
do
{
clrscr();
printf("1.create list\n");
printf("2.add at begining\n");
printf("3.add after \n");
printf("4.display\n");
printf("5.exit\n");
/*printf("6.search\n");
printf("7.quit\n");*/
printf("enter ur choie\n");
scanf("%d",&choice);
switch(choice)
{
case 1:
head=NULL;
printf("how many node u want::\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("enter the element;;\n");
scanf("%d",&m);
create_list(m);
}
break;
case 2:
printf("enter the element :");
scanf("%d",&m);
addatbeg(m);
break;
case 3:
printf("enter the element::");
scanf("%d",&m);
prinf("enter the position after which this element inserted::\n");
scanf("%d",&position);
addafter(m,position);
break;
case 4:
display(list);
break;
case 5:
exit(0);
}
printf("continue ? (y/n)  \n");
ans=getche();
}
while(ans=='y'||ans=='Y');
getch();

}