#include<stdio.h>
#include<stdlib.h>

struct tnode
{
	struct tnode *lch,*rch;
	int data;
};

typedef struct tnode tnode;
tnode *getnode();

void tin();
void ino();
void pod();
void psod();
void tdis();
void tde();

void main()
{
	int a[50],i,n,it;
	tnode *rt;
	rt=NULL;
	printf("\nenter the num of elements");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		tin(&rt,a[i]);
	printf("\nBinary Tree\n");
	tdis(rt,1);
	printf("\nInorder traversal\n");
	ino(rt);
	printf("\nPreorder traversal\n");
	pod(rt);
	printf("\nPostorder traversal\n");
	psod(rt);
	printf("\nenter the item to delete =\t");
	scanf("%d",&it);
	tde(&rt,it);
	printf("\nBinary Tree\n");
	tdis(rt,1);
	getch();
}

void tin(tnode **rt,int it)
{
	tnode *cur=(*rt),*tmp;
	if((*rt)==NULL)
	{
		(*rt)=getnode();
		(*rt)->data=it;
		(*rt)->lch=NULL;
		(*rt)->rch=NULL;
		return;
	}
	while(cur!=NULL)
	{
		if(it<cur->data)
		{
			if(cur->lch!=NULL)
				cur-cur->lch;
			else
			{
				tmp=getnode();
				cur->lch=tmp;
				tmp->data=it;
				tmp->rch=NULL;
				tmp->lch=NULL;
				return;
			}
		}
		else
		{
			if(it>cur->data)
			{
				if(cur->rch!=NULL)
					cur=cur->rch;
				else
				{
					tmp=getnode();
					cur->rch=tmp;
					tmp->data=it;
					tmp->rch=NULL;
					tmp->lch=NULL;
					return;
				}
			}
			else
			{
				printf("wrong data");
				exit(0);
			}		
		}
	}
	
}

void tdis(tnode *rt,int l)
{
	int i;
	if((rt)!=NULL)
	{
		tdis((rt)->rch,l+1);
		printf("\n");
		for(i=0;i<l;i++)
			printf(" ");
		printf("%d",(rt)->data);
		tdis((rt)->lch,l+1);	
	}
}

tnode *getnode()
{
	tnode *t;
	t=(tnode*)malloc(sizeof(tnode));
	return t;
}

void ino(tnode *rt)
{
	if(rt!=NULL)
	{
		ino(rt->lch);
		printf("\n%d",rt->data);
		ino(rt->rch);
	}
	else
		return;
}

void pod(tnode *rt)
{
	if(rt!=NULL)
	{
		printf("\n%d",rt->data);
		pod(rt->lch);
		pod(rt->rch);
	}
	else
		return;
}

void psod(tnode *rt)
{
	if(rt!=NULL)
	{
		psod(rt->lch);
		psod(rt->rch);
		printf("\n%d",rt->data);
	}
	else
		return;
}

void tde(tnode **rt,int it)
{
	tnode *cur;
	if(*rt==NULL)
	{
	printf("error");
	return;
	}
	if(it<(*rt)->data)
		tde(&((*rt)->lch),it);
	else
	{
		if(it>(*rt)->data)
			tde(&((*rt)->rch),it);
		else
		{
			if(cur->lch==NULL)
			{
				(*rt)=(*rt)->rch;
				free(cur);
			}
			else
			{
				cur=(*rt)->rch;
				while(cur->lch!=NULL)
					cur=cur->lch;
				cur->lch=(*rt)->lch;
				cur=(*rt);
				(*rt)=(*rt)->rch;
				free(cur);
			}
		}
	}
}
