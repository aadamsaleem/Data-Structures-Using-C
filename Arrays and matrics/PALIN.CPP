/* Palindrome*/

#include <stdio.h>
#include <conio.h>
#include <string.h>
void main ( )
{
clrscr();
char str[20], flag;
int i,j;
printf ("\n Enter the string");
gets(str);
flag='y';
printf("\n The string is \t");
for (i=0;str[i] !='\0'; i++)
printf ("%c",str[i]);
for (j=0,i=i-1; i>j; j++,i--)
{
if (str[i]!=str[j])
{
flag = 'n';
break;
}
}
if (flag =='n')
printf ("\nString is not palindrome");
else
printf ("\nString is palindrome");
getch ( );
}
