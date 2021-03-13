#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node * next;
	int data;
};
typedef struct node nd;

nd *getnode()
{
	nd *tmp;
	tmp=(nd*)malloc(sizeof(nd));
	return tmp;
}

nd *f=NULL;
nd *r=NULL;

void in(int it)
{
	nd *t;
	t=getnode();
	if(t==NULL)
		printf("\nFULL\n");
	else
	{
		t->data=it;
		t->next=NULL;
		if(f==NULL)
			f=r=t;
		else
		{
			r->next=t;
			r=t;
		}
	}
}


void dis(nd *p)
{
	while(p!=NULL)
	{
		printf("%d\t",p->data);
		p=p->next;
	}	
}


int del()
{
	int a;
	nd *d=f;
	if(d==NULL)
		printf("\nFULL");
	else
	{
		f=f->next;
		a=d->data;
		free(d);
	}
	return a;
}

void main()
{
	dis(f);
	in(5);
	in(6);
	in(2);
	in(9);
	dis(f);
	del();
	dis(f); 
	
}
