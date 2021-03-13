#include<stdio.h>
#include<stdlib.h>

struct nd
{
	int data;
	struct node * n;
};
typedef struct nd node;

node *h;

node *getnode()
{
	node *tmp;
	tmp=(node *)malloc(sizeof(node));
	return tmp;
}

void pu()
{
	int it;
	node *t;
	t=getnode();
	if(t==NULL)
		printf("\nData cannot be inserted\n");
	else
	{
		printf("\nENter element : ");
		scanf("%d",&it);
		if(h==NULL)
		{
			t->data=it;
			t->n=NULL;
			h=t;
		}
		else
		{
			t->data=it;
			t->n=h;
			h=t;
		}
	}
}

void pop()
{
	int it;
	node *t;
	if(h==NULL)
		printf("EMpty");
	else
	{
		it=h->data;
		t=h;
		h=h->n;
		free(t);
		printf("POPPED");
	}
}

void dis()
{
	node *p;
	p=h;
	if(p==NULL)
		printf("\nUndeflow");
	else 
	{
		while(p!=NULL)
		{
			printf("\t%d",p->data);
			p=p->n;
		}
	}
}


int main()
{
	int ch;
	while(1)
	{
		printf("\n1.push\n2.pop\n3.dis\n4.dis");
		printf("\nENter choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				pu();
				break;
			case 2:
				pop();
				break;
			case 3:
				dis();
				break;
			case 4:
				exit(0);
		}
	}	
}
