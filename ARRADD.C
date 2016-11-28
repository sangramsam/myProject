#include<stdio.h>
#include<conio.h>
void main()
{
int a[2][2];
int b[2][2];
int i,j;
int c[2][2];
clrscr();
printf("plz insert the values of matrix a\n");
for(i=0;i<2;i++)
{
for(j=0;j<2;j++)
{
scanf("%d",*(a+i)+j);
}
}
printf("plz insert the values of matrix b\n");
for(i=0;i<2;i++)
{
for(j=0;j<2;j++)
{
scanf("%d",*(b+i)+j);
}
}
printf("matrix are \n");
for(i=0;i<2;i++)
{
for(j=0;j<2;j++)
{
printf("%d\t",*(*(a+i)+j));
}
printf("\n");
}
for(i=0;i<2;i++)
{
for(j=0;j<2;j++)
{
printf("%d\t",*(*(b+i)+j));
}
printf("\n");
}
printf("addition of matrixes isss-----\n");
for(i=0;i<2;i++)
{
for(j=0;j<2;j++)
{
c[i][j]=a[i][j]+b[i][j];
printf("%d\t",*(*(c+i)+j));
}
printf("\n");
}
getch();
}