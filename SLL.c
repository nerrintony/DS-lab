#include<stdio.h>

struct nd
{
int info;
struct nd *link;
}*start;

void inf(int data)
{
	struct nd *q;
	struct nd *temp;
	temp = (struct nd*)malloc(sizeof(struct nd));
	temp->info=data;
	temp->link=NULL;
	if(start==NULL)
		start=temp;
	else
	{
		q=start;
		while(q->link!=NULL)
			q=q->link;
		q->link=temp;
	}
}

void dis()
{
	struct nd *q;
	if(start==NULL)
		printf("\nlist empty\n");
	q=start;
	printf("\nlist:");
	while(q!=NULL)
	{
		printf("%d\t",q->info);
		q=q->link;
	}
	return;
}

int main()
{
	int n=0,i,m;
	start=NULL;
	printf("\nEnter the number\n");
	scanf("%d",&n);
	printf("\nenter the elements\n");
	for(i=0;i<=n;i++)
	{
		scanf("%d\t",&m);
		inf(m);
	}
dis();
}
