/* Find length of string */

#include <stdio.h>
#include <conio.h>
#define MAXSIZE 100
void main ( )
{
int len=0;
char *p,str[MAXSIZE];
clrscr ( );
printf ("enter the string: \n");
scanf ("%s", str);
p=str;
while(*p!='\0')
{
p=p+1;
len = len+1;
}
printf ("The length of the string is %d", len);
getch ();
}
