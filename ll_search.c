#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *link;
	int data;
};
typedef struct node nd;

nd *get()
{
	nd* tmp;
	tmp=(nd*)malloc(sizeof(nd));
	return tmp;
}

nd *s;

void in_b(int it)
{
	nd *t;
	t=get();
	if(t==NULL)
		printf("\nNOT POSSIBLE\n");
	else
	{	
		t->data=it;
		t->link=s;
		s=t;	
	}
}


void in_a(int it)
{
	nd *t;
	nd *l=s;
	t=get();
	t->data=it;
	t->link=NULL;
	while(l->link!=NULL)
		l=l->link;
	l->link=t;
}

void in_m(nd *n,int it)
{
	nd *t;
	t=get();
	t->data=it;
	t->link=n->link;
	n->link=t;
	
}

void dis()
{
	nd *t;
	t=s;
	if(t==NULL)
		printf("\nEMPTY");
	else 
	{
		while(t!=NULL)
		{
			printf("%d\t",t->data);
			t=t->link;
		}
	}
}

void del_b(int key)
{
	nd *t=s,*p;
	if(t!=NULL && t->data==key)
	{
		s=t->link;
		free(t);
	}
	while(t!=NULL && t->data!=key)
	{
		p=t;
		t=t->link;
	}
	if(t==NULL)
		return;
	p->link=t->link;
	free(t);
}

int se(int key)
{
	int in=0;
	nd *t=s;
	while(t!=NULL && t->data!=key)
	{
		in++;
		t=t->link;
	}
	return (t!=NULL)?in:-1;
}

void main()
{
	printf("\nSTART\n");
	in_b(5);
	in_b(4);
	in_b(7);
	in_b(9);
	in_b(1);
	dis();
	printf("\n\nIN end\n\n");
	in_a(23);
	in_a(346);
	dis();
	printf("\n\nIN mid\n\n");
	in_m(s->link,555);
	dis();
	printf("\n\n");
	del_b(9);
	del_b(5);
	int in;
	dis();
	in=se(555);
	printf("\n\n%d",in+1);
	
}
