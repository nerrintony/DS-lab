#include<stdio.h>

#define CAP 5
int st[CAP],t=-1;

void push(int);
void pop();
int full();
int empty();
void peek();
void tra();

int main()
{
	int ele,ch;
	
	while(1)
	{
		printf("\n1.Push\t2.Pop\t3.Peek\t4.Traverse\n");
		printf("\nEnter your choice : ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				printf("\nEnter the element : ");
				scanf("%d",&ele);
				push(ele);
				break;
			
			case 2:
				pop();
				break;
			
			case 3:
				peek();
				break ;
			
			case 4:
				tra();
				break;
			
			case 5:
				exit(0);	
		}
	}
}

int full()
{
	if(t==CAP)
		return 1;
	else
		return 0;
}

int empty()
{
	if(t==-1)
		return 1;
	else 
		return 0;
}

void push(int it)
{
	if(full())
		printf("\nStack Overflow\n");
	else 
	{
		t++;
		st[t]=it;
		printf("\nPushed\n");
	}
}

void pop()
{
	if(empty())
		printf("\nUndeflow\n");
	else
	{
		printf("\nPopped item : %d",st[t--]);
	}
}

void peek()
{
	if(empty())
		printf("\nUnderflow\n");
	else
		printf("\ntop : %d",st[t]);
}

void tra()
{
	int i;
	if(empty())
		printf("\nUnderflow\n");
	else 
	{
		for(i=0;i<t+1;i++)
			printf("\t%d",st[i]);
	}
}
