#include<stdio.h>
#include<windows.h>

int o=0;
struct node
{
        int data;
        struct node * l;
        struct node * r;
        
};

typedef struct node node;

node *list[15]={NULL},*root=NULL;

void gotoxy(short x, short y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}



void display ( node * ptr,int space,int ps,int line)
{
    if(ptr==NULL)
    return;
    o++;
     gotoxy(space,line);
	
     printf(" %d",ptr->data);
     
     display(ptr->l,space - ps,ps/2,line+2);
     display(ptr->r,space + ps,ps/2,line+2);
}    


int findmin(int size)
{
    int i,pos=0;
    int min=3333333;
    for(i=0;i<size;i++)
    {                  if(list[i]!=NULL)
                       if(list[i]->data < min)
                       {
                                        min=list[i]->data;
                                        pos=i;
                       }
    }
    return pos;
}
    
    
void createtree(int size)
{
     int count=0,min1,min2;
     node * add1,*add2,* newnode;
     while(count<size-1)
     { 
                      min1=findmin(size);
                      add1=list[min1];
                      list[min1]=NULL;
                     
                      min2=findmin(size);
                      add2=list[min2];
                      list[min2]=NULL;
                      printf("%d %d\n",add1->data,add2->data);
                      newnode=(node *)malloc(sizeof(node));
                      newnode->data= add1->data + add2->data;
                      newnode->l=add1;
                      newnode->r=add2;
                      
                      list[min1]=newnode;
                      count++;
     }
     
     root=list[min1];
     
}     
                     
                      
void inorder(node * ptr)
{
     if(ptr==NULL)
        return;
     inorder(ptr->l);
     printf(" %d",ptr->data);
     inorder(ptr->r);
}

void preorder(node * ptr)
{
     if(ptr==NULL)
        return;
     printf(" %d",ptr->data);
     preorder(ptr->l);
     preorder(ptr->r);
}


void postorder(node * ptr)
{
     if(ptr==NULL)
         return;
     postorder(ptr->l);
     postorder(ptr->r);
     printf(" %d",ptr->data);
}
 
void main ()
{
    int choice,input,i;
    
    while(1)
    {
         system("cls");
         printf("\n\n\t\t\t\tEXPRESSION TREE\n\t\t\t\tby Aadam Saleem\n\t\t\t\t11-CSS-01\n\n");
         display(root,32,16,15);
         printf("\n\n\t\t1.Create Tree");
         printf("\n\t\t2.Traversals");
         printf("\n\t\t3.Display node");
         printf("\n\t\t4.Exit");
         printf("\n\n\t\tEnter Choice : ");
         
         scanf("%d",&choice);
         
         switch(choice)
         {
                   case 1: printf("\n\t\tEnter values (0 to finish) :");
                           i=0;
                           do
                           {
                               scanf("%d",&input);
                               list[i]=(node*)malloc(sizeof(node));
                               list[i]->data=input;
                               list[i]->l=NULL;
                               list[i]->r=NULL;
                               i++;
                          
                           }while( input!=0 );
                            
                           createtree(i-1);
                           display(root,32,16,15);
                           break;
                           
                   case 2:  display(root,32,16,15);
                		 	printf("\n\t\tPreorder   : ");
                		 	preorder(root);
                		 	printf("\n\t\tInorder    : ");
                		 	inorder(root);
                		 	printf("\n\t\tPostorder  : ");
                		 	postorder(root);
                		 	getch();
                		 	break;
                   case 3: display(root,32,16,15);
                           break;
                   case 4: exit(0);       
         } 
     
     }             
     getch();                     
}
