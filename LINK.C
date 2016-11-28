#include<stdio.h>
#include<malloc.h>
struct node{
int value;
struct node *next;
};
void Init(struct node *root)
{
root->next=NULL;
}
void Push(struct node *root,int value)
{
struct node *j =(struct node*)malloc(sizeof(struct node));
j->next=root->next;
j->value=value;
root->next=j;
printf("Value Pushed is %d",value);
}
void Pop(struct node *root)
{
if(root->next == NULL){
printf("No Element to Pop");
}
else
{
struct node *temp;
temp=root->next;
root->next=temp->next;
printf("Value Popped is %d",temp->value);
free(temp);
}
}
void main()
{
struct node stack;
clrscr();
Init(&stack);
Push(&stack,10);
Push(&stack,60);
Pop(&stack);
Pop(&stack);
getch();
}
