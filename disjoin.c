#include<stdio.h>

struct disj
{
	int p[10],r[10],n;
}dis;

void crset()
{
	int i;
	for(i=0;i<dis.n;i++)
	{
		dis.p[i]=i;
		dis.r[i]=0;
	}
}

void sh()
{
	int i;
	printf("\nParent\n");
	for(i=0;i<dis.n;i++)
		printf("%d",dis.p[i]);
	printf("\nRank\n");
	for(i=0;i<dis.n;i++)
		printf("%d",dis.r[i]);
	printf("\n");
}

int fin(int x)
{
	if(dis.p[x]!=x)
		dis.p[x]=fin(dis.p[x]);	
	return dis.p[x];
}

void un(int x,int y)
{
	int xs=fin(x);
	int ys=fin(y);
	if(xs==ys)
		return;
	if(dis.r[xs]<dis.r[ys])
	{
		dis.p[xs]=ys;
		dis.r[xs]=-1;
	}
	else if(dis.r[xs]>dis.r[ys])
	{
		dis.p[ys]=xs;
		dis.r[ys]=-1;
	}
	else
	{
		dis.p[ys]=xs;
		dis.r[xs]=dis.r[xs]+1;
		dis.r[ys]=-1;
	}
}

void main()
{
	int n,x,ch,w,y;
	printf("\nHow many nodes?");
	scanf("%d",&dis.n);
	crset();
	do
	{
		printf("\nDisjoin Set");
		printf("\n1.Union\n2.Find\n3.Display\n");
		printf("\nenter ur choice\t");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter Elements");
				scanf("%d%d",&x,&y);
				un(x,y);
				break;
			case 2:
				printf("Check connection");
				scanf("%d%d",&x,&y);
				if(fin(x)==fin(y))
					printf("\nconnected\n");
				else
					printf("\nnot connected");
				break;
			case 3:
				sh();
				break;
		}
		printf("\nContinue?(1/0)");
		scanf("%d",&w);
	}while(w==1);
}
