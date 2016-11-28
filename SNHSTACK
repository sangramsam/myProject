#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define size 5
struct stack
{
int s[size];
int top;
}st;
int stfull()
{
if(st.top>=size-1)
return 1;
else
return 0;
}
void push(int item)
{
st.top++;
st.s[st.top]=item;
}
int stempty()
{
if(st.top==-1)
return 1;
else
return 0;
}
int pop()
{
int item;
item=st.s[st.top];
st.top--;
return(item);
}
void display()
{
int i;
if(stempty())
printf("\n stack is empty");
else
{
for(i=st.top;i>=0;i--)
printf("\n%d",st.s[i]);
}
}
void main()
{
int item,choice;
char ans;
st.top=-1;
clrscr();
printf("\n\t\t implementation of stack");
do
{
printf("\n main menu");
printf("\n1.push2.pop3.display4.exit");
printf("\n enter your choice");
scanf("%d",&choice);
switch(choice)
{
case 1:
printf("enter the item to be pushed\n");
scanf("%d",&item);
if(stfull())
printf("\n stack is full");
else
push(item);
break;
case 2:
if(stempty)
printf("\n empty stack");
else
item=pop();
printf("the poped element is%d",item);
break;
case 3:
display();
break;
case 4:
exit(0);
break;
}
printf("\n do u want to continue");
ans=getche();
}
while(ans=='y'||ans=='Y');
getch();
}
