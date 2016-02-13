   #include <stdio.h>
   #include <conio.h>
   #include <string.h>
   void main ( )
   {
   int ch, i, j, n;
   char names[25][30], t[30];
   clrscr();
   printf ("Enter number of strings");
   scanf ("%d", &n);
   printf ("Enter the strings : \n");
   for (i=0; i<=n; i++)
   gets(names[i]);
   for (i=0; i<=n; i++)
   printf ("\n%s", names[i]);
   printf ("\n\n Enter your choice \n");
   printf ("1. Ascending order....\n");
   printf ("2. Descending order....\n");
   scanf ("%d", &ch);
   switch (ch)
   {
   case 1 :
   for (i=0;i<=n; i++)
    {
     for (j=i+1; j<=n; j++)
      {
	    if(strcmp(names[i],names[j])>0)
	       {
		 strcpy (t,names[i]);
		 strcpy(names[i],names[j]);
		 strcpy(names[j],t);
		}
       }
     }
   printf ("\nSorted in Ascending order \n");
   for (i=0;i<=n; i++)
       puts (names[i]);
   break;

   case 2 :
   for (i=0;i<=n;i++)
   {
     for (j=i+1; j<=n; j++)
      {
	 if (strcmp(names[i],names[j])<0)
	  {
	     strcpy(t,names[i]);
	     strcpy(names[i],names[j]);
	     strcpy(names[j],t);
	   }
       }
   }
   printf ("\nSorted in Descending order \n");
   for (i=0;i<=n; i++)
      puts (names[i]);
   break;
   }
   getch ();
   }
