#include<stdio.h>
#include<conio.h>

struct treenode
{
	char c;
	struct treenode * rlink;
	struct treenode * llink;
}*stc[30],*temp,*root;

char prefix[20],ch;
int topt=-1,max=50,len;

void pusht(struct treenode * p);
struct treenode* popt();
void tredis(struct treenode *ptr,int level);
void exptree();
void post(struct treenode* p);

int main()
{
	system("cls");
	printf("\n\n\t\t\t\tEXPRESSION TREE\n\t\t\t\tby Aadam Saleem\n\t\t\t\t11-CSS-01\n\n");
	printf("\n\t\tEnter a prefix expression	:");
	scanf("%s",prefix);
	exptree();
	tredis(root,1);
	printf("\n\n\t\tThe postfix expression is	:");
	post(root);
	getch();
}

void post(struct treenode* p)
{
	if(p!=NULL)
	{
		post(p->llink);
		post(p->rlink);
		printf("%c",p->c);
	}
}

void exptree()
{
	int i;
	len=strlen(prefix);
	i=len-1;
	while(i>=0)
	{
		switch(prefix[i])
		{
			case '+':
			case '-':
			case '*':
			case '/':
			case '^':
				temp=(struct treenode*)malloc(sizeof(struct treenode));
				temp->c=prefix[i];
				temp->llink=popt();
				temp->rlink=popt();
				pusht(temp);
				break;

			default :
				temp=(struct treenode*)malloc(sizeof(struct treenode));
				temp->c=prefix[i];
				temp->rlink=NULL;
				temp->llink=NULL;
			
	pusht(temp);
		}
		i--;
	}
	root=stc[topt];
}


void pusht(struct treenode * p)
{
	if(topt==max)
		printf("\nBeyond Capacity");
	else
		stc[++topt]=p;
}

struct treenode* popt()
{
	if(topt==-1)
	{
		printf("\nNo Expression");
		return 0;
	}
	else
		return(stc[topt--]);
}

void tredis(struct treenode *ptr,int level)
{
	int i;
	if ( ptr!=NULL )
	{
		tredis(ptr->rlink, level+1);
		printf("\n");
		for (i = 0; i < level; i++)
			printf("    ");
		printf("%c", ptr->c);
		tredis(ptr->llink, level+1);
	}
}
