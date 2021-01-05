#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node 
{
	int data;
	struct node *link;
};
typedef struct node node;
node *getnode();

node *getnode()
{
	node *p;
	p=(node*)malloc(sizeof(node));
	return(p);
}
freenode(node *p)
{
free(p);
}

void in();
void inll();
void dis();
void cr();
void del();

 
void main()
{
	node *st, *en;
	int ch=0,n,it,p;
	inll(&st,&en);
	printf("\nenter the num of elements\n");
	scanf("%d",&n);
	cr(&st,&en,n);
	while(1)
	{
		printf("\n\n\t\tCircular LL\n\n\n1.Insertion\n\n2.Deletion\n\n3.display\n\n4.exit\n");
		scanf("\t%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nenter element and position\n");
				scanf("%d%d",&it,&p);
				in(&st,&en,it,p);
				break;
				
			case 2:
				printf("position to delete");
				scanf("%d",&p);
				del(&st,&en,p);
				break;
				
			case 3:
				dis(&st,&en);
				break;

			default:
				printf("\nInvalid\n");
				
		}
	}
	getch();
}
 
 void cr(node **st,node **en,int n)
 {
 	node *tmp;
 	int it,i;
 	for(i=1;i<=n;i++)
 	{
 		printf("\nenter the ele\t");
 		scanf("%d",&it);
 		tmp=getnode();
 		tmp->data=it;
 		if((*st)==NULL)
 			*st=tmp;
 		else
 			(*en)->link=tmp;
 		*en=tmp;
	 }
 }
 
 void inll(node **st,node **en)
 {
 	(*st)=NULL;
 	(*en)=NULL;
 }
 
 void in(node **st,node **en,int it,int p)
 {
 	node *cur,*tmp;
 	int i=2;
 	tmp=getnode();
 	if(*st==NULL)
 	{
 		tmp->data=it;
 		tmp->link=*st;
 		if(*en==NULL)
 			*en=tmp;
 		else
 			(*en)->link=tmp;
 		*st=tmp;
 		return;
	 }
	 cur=*st;
	 while(cur->link!=NULL)
	 {
	 	if(i==p)
	 	{
		 tmp->data=it;
		 tmp->link=cur->link;
		 cur->link=tmp;
		 return;	 	
		 }
		 else
		 {
		 	i++;
		 	cur=cur->link;
		 }
	 }
	 tmp->data=it;
	 tmp->link=cur->link;
	 cur->link=tmp;
	 *en=tmp;
 }
 
 void del(node **st,node **en,int p)
 {
 	node *cur,*tmp;
 	int it,i=2;
 	if(*st==NULL)
 	{
 		printf("list empty\n");
 		return;
	 }
	 if(p==1)
	 {
	 	cur=*st;
	 	it=cur->data;
	 	if((*st)->link==*st)
	 		*st=*en=NULL;
	 	else
	 	{
		 	*st=(*st)->link;
	 		(*en)->link=*st;
		 }
	 	freenode(cur);
	 	printf("\nDeleted item\t%d",it);
	 }
	 cur=*st;
	 while(cur->link!=*st)
	 {
	 	if(i==p)
	 	{
	 		tmp=cur->link;
	 		it=tmp->data;
	 		cur->link=tmp->link;
	 		freenode(tmp);
	 		printf("\nDeleted item\t%d",it);
	 		return;
		 }
		 else
		 	cur=cur->link;
		i++;
	 }
	 printf("\n\ninvalid abc\n\n");
 }
 

void dis(node *st, node *en)
 {
 	if(st==NULL)
 	{
 		printf("\nlist empty\n");
 		return;
	 }
	 printf("\n\nstart->");
	 do
	 {
	 	printf("%d",st->data);
	 	st=st->link;
	 }while(en->link!=st);
	 printf("end");
 }
