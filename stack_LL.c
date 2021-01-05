#include<stdio.h>

struct node
{
	int info;
	struct node *link;
}*top=NULL;

void main()
{
	int ch;
	while(1)
	{
		printf("\n1.Push");
		printf("\n2.Pop");
		printf("\n3.Display");
		printf("\n4.Quit");
		printf("\nEnter your choice\t");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				dis();
				break;
			case 4:
				exit(1);
			default:
				printf("\nInvalid\n");
		}
	}
}

void push()
{
	struct node *temp;
	int pu;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\nenter the elements");
	scanf("%d",&pu);
	temp->info=pu;
	temp->link=top;
	top=temp;
}

void pop()
{
	struct node *temp;
	if(top==NULL)
		printf("\nstack is empty\n");
	else
	{
		temp=top;
		printf("\npopped\t%d",temp->info);
		top=top->link;
		//free(temp);
	}
}

void dis()
{
	struct node *ptr;
	ptr=top;
	if(top=NULL)
		printf("\nstack empty");
	else
	{
		printf("\nstack ele:\t");
		while(ptr!=NULL)
		{
			printf("%d",ptr->info);
			ptr=ptr->link;
		}
	}
}
