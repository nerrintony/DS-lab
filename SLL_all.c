#include<stdio.h>
#include<conio.h>

struct nd
{
int data;
struct nd *link;
}*hd;

void inf()
{
	struct nd *ptr;
	int it;
	ptr=(struct nd *)malloc(sizeof(struct nd*));
	if(ptr==NULL)
	{
		printf("\nOverflow");
		return;
	}
	else
	{
		printf("\nenter value\n");
		scanf("%d",&it);
		ptr->data=it;
		ptr->link=hd;
		hd=ptr;
	}
}

void inl()
{
	struct nd *ptr,*tmp;
	int it;
	ptr=(struct nd *)malloc(sizeof(struct nd*));
	if(ptr==NULL)
		printf("\nOverflow\n");
	else
	{
		printf("\nenter value\n");
		scanf("%d",&it);
		ptr->data=it;
		if(hd==NULL)
		{
			ptr->link=NULL;
			hd=ptr;
		}
		else
		{
			tmp=hd;
			while(tmp->link!=NULL)
				tmp=tmp->link;
			tmp->link=ptr;
			ptr->link=NULL;
		}
	}
}

void inany()
{
	int i,l,it;
	struct nd *ptr,*tmp;
	ptr=(struct nd *)malloc(sizeof(struct nd*));
	if(ptr==NULL)
		printf("\nOverflow");
	else
	{
		printf("\nenter value");
		scanf("%d",&it);
		ptr->data=it;
		printf("\nLocation\t");
		scanf("%d",&l);
		tmp=hd;
		for(i=0;i<l;i++)
		{
			tmp-tmp->link;
			if(tmp==NULL)
				printf("\nInsertion failed\n");
		}
		ptr->link=tmp->link;
		tmp->link=ptr;
	}
}

void def()
{
	struct nd *ptr;
	if(hd==NULL)
		printf("\nempty\n");
	else
	{
		ptr=hd;
		hd=ptr->link;
		free(ptr);
	}
}

void del()
{
	struct nd *ptr,*ptr1;
	if(hd==NULL)
		printf("\nempty\n");
	else if(hd->link==NULL)
	{
		hd=NULL;
		free(hd);
	}
	else
	{
		ptr=hd;
		while(ptr->link!=NULL)
		{
			ptr1=ptr;
			ptr=ptr->link;
		}
		ptr1->link=NULL;
		free(ptr);
	}
}

void deany()
{
	struct nd *ptr,*ptr1;
	int l,i;
	printf("\nlocation\t");
	scanf("%d",&l);
	ptr=hd;
	for(i=0;i<l;i++)
	{
		ptr1=ptr;
		ptr=ptr->link;
		if(ptr==NULL)
			printf("\ncan't dalete\n");
	}
	ptr1->link=ptr->link;
	free(ptr);
}

void trv()
{
	struct nd *ptr;
	int it,i=0,f;
	ptr=hd;
	if(ptr==NULL)
		printf("\nempty\n");
	else
	{
		printf("\nElement to search\t");
		scanf("%d",&it);
		while(ptr!=NULL)
		{
			if(ptr->data==it)
			{
				printf("\niten at loc => ",++i);
				f=0;
			}
			else
				f=-1;
			i++;
			ptr=ptr->link;	
		}
		if(f==-1)
			printf("\nitem not found\n");
	}
}

void dis()
{
	struct nd *ptr;
	ptr=hd;
	if(ptr==NULL)
		printf("\nlist empty\n");
	else
	{
		printf("\nlist:");
	}
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->data);
		ptr=ptr->link;
	}
}

int main()
{

	int ch;
	while(ch!=9)
	{
		printf("\n1.Insert First\t2.insert last\t3.Insert Any");
		printf("\n4.Delete First\t5.Delete Last\t6.Delete Any");
		printf("\n7.Traverse\t8.Display\t9.Exit\n");
		printf("\nenter your choice\t");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				inf();
				break;
			case 2:
				inl();
				break;
			case 3:
				inany();
				break;
			case 4:
				def();
				break;
			case 5:
				del();
				break;
			case 6:
				deany();
				break;
			case 7:
				trv();
				break;
			case 8:
				dis();
				break;
			case 9:
				exit(0);
				break;
			default:
				printf("\ninvalid");	
		}
	}
	getch();
}
