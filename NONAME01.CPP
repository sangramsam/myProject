#include<stdio.h>
#inlude<conio.h>
struct emp
{
int emp_no;
int basic_pay;
int da;
int cca;
}
void main()
{
int i;
struct emp e[3];
for(i=0;i<3;i++)
{
printf("enter the emp_no\n");
scanf("%d",&e[i].emp_no);
print("enter the basic_pay\n");
scanf("%d",&e[i].basic_pay);
}
for(i=0;i<3;i++)
{
printf("emp_no=%d\t",e[i].emp_no);
printf("DA=%d\t",e[i]=


