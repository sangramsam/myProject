#include<stdio.h>
#include<stdlib.h> 
#include<string.h> 
struct stack 
{ 
int top; 
char item[100]; 
}; 
int empty(struct stack *s) 
{ 
if (s->top==-1) 
return 1; 
else 
return 0; 
} 
char popandtest(struct stack *ps) 
{ 
return (ps->item[ps->top--]); 
} 
void pushandtest(struct stack *ps,char symb) 
{ 
ps->top=ps->top+1;; 
ps->item[ps->top]=symb; 
} 
int ISDIGIT(char symb) 
{ 
if (symb>='0' && symb<='9') 
{ 
return 1; 
} 
else 
{ 
return 0; 
} 
} 
double power(double op1,double op2) 
{ 
int i; 
double op11; 
op11=op1; 
for (i=1;i<op2;i++) 
{ 
op1=op1*op11; 
} 
return op1; 
} 
double oper(char symb,double op1,double op2)
{
switch (symb)
{
case '+':
return (op1+op2);
break;
case '-':
return (op1-op2);
break;
case '*':
return (op1*op2);
break;
case '/':
return (op1/op2);
break;
case '$':
return (power(op1,op2));
break;
default:
printf("invalid operator\n");
return 0;
break;
}
}
double evalpre()
{
struct stack ps;
int len;
int i,Break;
char string[100];
char symbol,top1,top2;
double op1,op2,value;
char symbol2;
int count=0;
ps.top=-1;
printf("Enter expression in prefix form values\n");
scanf("%s",string);
len=strlen(string);
for (i=0;i<len;i++)
{
symbol=string[i];
if(ps.top>=1)
if(ISDIGIT(top1=ps.item[ps.top])==1 && ISDIGIT(top2=ps.item[ps.top-1])==1)
{
Break=1;

while(Break!=0)
{
op2=(double)popandtest(&ps)-'0';
op1=(double)popandtest(&ps)-'0';
symbol2=popandtest(&ps);
value=oper(symbol2,op1,op2);
pushandtest(&ps,(char)value);
top1=ps.item[ps.top];
top2==ps.item[ps.top-1];
if(ISDIGIT(top1)==1 && ISDIGIT(top2)==1)
Break=1;
else
Break=0;
}
pushandtest(&ps,symbol);
}
else
pushandtest(&ps,symbol);
}
//char symbol2;
while(ps.top!=0)
{
op2=(double)popandtest(&ps)-'0';
op1=(double)popandtest(&ps)-'0';
symbol2=popandtest(&ps);
value=oper(symbol2,op1,op2);
pushandtest(&ps,(char)value);
}
printf("top=%d\n",ps.top);
value=((double)(popandtest(&ps)-'0'));
return (value);
}
int main()
{
double val;
val=evalpre();
printf("value = %f\n",val);
return 0;
}

