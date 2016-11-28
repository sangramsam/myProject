#include<stdio.h>
#include<conio.h>
#define SIZE 50
#include <ctype.h>
int s[SIZE];
int top=-1;

push(int elem)
{
 s[++top]=elem;
}

int pop()
{
 return(s[top--]);
}

main()
{
 char pofx[50],ch;
 int i=0,op1,op2;
 printf("\n\nRead the Postfix Expression ? ");
 scanf("%s",pofx);
 while( (ch=pofx[i++]) != '\0')
 {
  if(isdigit(ch)) push(ch-'0');
  else
  {
   op2=pop();
   op1=pop();
   switch(ch)
   {
   case '+':push(op1+op2);break;
   case '-':push(op1-op2);break;
   case '*':push(op1*op2);break;
   case '/':push(op1/op2);break;
   }
  }
 }
 printf("\n Given Postfix Expn: %s\n",pofx);
 printf("\n Result after Evaluation: %d\n",s[top]);
}