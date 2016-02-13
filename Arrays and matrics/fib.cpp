/* Generate Fibonacci series*/

#include <stdio.h>
#include <conio.h>
void main ( )
{
clrscr();
int a [100], i, n;
printf ("Input total no. of terms\n");
scanf ("%d", &n);
a[0] = 0;
a[1] = 1;
for (i = 2; i < n; ++i)
a[i] = a[i-1] + a[i-2];
printf ("Terms of Fibonacci series :\n");
for (i = 0; i<n; ++i)
printf ("%d,", a[i]);
getch ();
}
