/* Sort a list of N string using insertion sort */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
void main( )
{
int i=0,j,k,m;
char fname[10], name[200][30],s[30];
FILE *fp;
clrscr( );
printf("Enter the file name\n");
scanf("%s", fname);
fp=fopen(fname, "r");
if(fp==NULL)
{
printf("Can't open ..........\n");
exit(0);
}
printf("The names in %s file are\n", fname);
for(;;)
{
fscanf(fp,"%s",s);
if(feof(fp))/* reads the names from the file */
break;
strcpy(name[i++],s);     /*store the name taken from the file int array*/
printf("%s",s);
}
m=i;
printf("\nThe sorted order is \n");
for(j=0;j<m;j++)
{ strcpy(s,name[j]);
for(k=j-1; (k>=0 && strcmp(name[k],s)>0);k--)
{
strcpy(name[k+1],name[k]);
}
strcpy(name[k+1],s);
}
for(i=0;i<m;i++)
printf("%s\n", name[i]);
getch( );
}
