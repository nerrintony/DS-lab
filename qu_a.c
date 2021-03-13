#include<stdio.h>
#define CAP 5

int q[CAP],f=0,r=0;

void in()
{
	int it;
	if(CAP==r)
		printf("\nQueue full");
	else
	{
		printf("\nEnter ele : ");
		scanf("%d",&it);
		q[r]=it;
		r++;
	}
}

void de()
{
	int i;
	if(f==r)
		printf("\nQueue empty");
	else
	{
		for(i=0;i<r-1;i++)
			q[i]=q[i+1];
		r--;
	}
}

dis()
{
	int i;
	if(f==r)
		printf("\nQueue empty");
	else
	{
		for(i=f;i<r;i++)
			printf("%d\t",q[i]);
	}
}

int main()
{
	int ch;
	while(1)
	{
		printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
		printf("\nenter choice : ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				in();
				break;
				
			case 2:
				de();
				break;
			
			case 3:
				dis();
				break;
			
			case 4:
				exit(0);
		}
	}
}
