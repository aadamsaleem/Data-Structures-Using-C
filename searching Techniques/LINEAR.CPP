/* Implementation of Linear Search*/

#include<stdio.h>
#include<conio.h>
void main()
{
char ch;
int arr[50],n,i,item;
clrscr();
printf("\nHow many elements you want to enter in the array:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("\nEnter element %d:",i+1);
scanf("%d",&arr[i]);
}
printf("\n\nPress any key to continue.....");
getch();
do
{
clrscr();
printf("\nEnter the element to be searched:");
scanf("%d",&item);
for(i=0;i < n;i++)
{
if(item == arr[i])
{
printf("\n%d found at position %d\n",item,i+1);
break;
}
}
if (i == n)
printf("\nItem %d not found in array\n",item);
printf("\n\nPress (Y/y) to continue: ");
fflush(stdin);
scanf("%c",&ch);
}while(ch == 'Y'|| ch == 'y');
}
