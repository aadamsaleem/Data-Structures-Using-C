/* Input element into array*/

#include <stdio.h>
#include <conio.h>
void main ( )
{
clrscr();
int a [100], i, n;
printf ("Input Range");
scanf ("%d", &n);
for (i = 0; i < n; ++i)
{
printf ("Input Element");
scanf ("%d", &a[i]);
}
printf ("Elements Are:\n");
for (i = 0; i < n; ++i)
printf ("%d\n", a[i]);
getch ( );
}