#include <stdio.h>

void in();
void out();
void un();
void insec();
void dif();

int a[]={0,0,0,0,0,0,0,0,0},b[]={0,0,0,0,0,0,0,0,0};
int c[]={0,0,0,0,0,0,0,0,0};

int main()
{
  	int ch,wish;
  	do
   	{
  	printf("\n\t\tSet Operation\n");
  	printf("1.Input\n2.Union\n3.Intersection\n4.Difference\n");
  	printf("enter choice\n");
  	scanf("%d",&ch);
  	switch(ch)
  	{
	case 1:
		in();
	    break;
    case 2:
		un();
	    break;
    case 3:
		insec();
	    break;
    case 4:
	 	dif();
	    break;
/*	default:
		printf("\ninvalid\n");*/
   	}
   	printf("\nDo you wish to continue ?(1/0)\n");
  	scanf("%d",&wish);
  	}while(wish==1);
 }

void in()
{
  	int n,x,i;
  	printf("Enter size of the 1st set\n");
  	scanf("%d",&n);
  	printf("\nEnter elements:\t");
  	for(i=1;i<=n;i++)
  	{
      	scanf("%d",&x);
    	a[x]=1;
  	}
  	printf("\nEnter size of the 2nd set\n");
  	scanf("%d",&n);
	printf("\nEnter elements:\t");
  	for(i=1;i<=n;i++)
  	{
  		scanf("%d",&x);
    	b[x]=1;
  	}
  	printf("\n1st set:\t");
  	for(i=1;i<=9;i++)
  		printf("%d",a[i]);
   	printf("\n2nd set:\t");
   	for(i=1;i<=9;i++)
   		printf("%d",b[i]);
}

void out(int c[])
{	
    int i;
    printf("\n Set is:\t");
    for(i=1;i<=9;i++)
    {
       	if (c[i]!=0)
       	printf("%d\t",i);
    }
   
}

void un()
{
  	int i,c[10];
  	for(i=1;i<=9;i++) 
    {
    	if(a[i]!=b[i])
        	c[i]=1;
    	else
			c[i]=a[i];
    }
  	for(i=1;i<=9;i++)  
   		printf("%d",c[i]);
   	out(c);
}

void insec()
{
  	int i,c[10];
  	for(i=1;i<=9;i++)
    {
    	if (a[i]==b[i])
			c[i]=a[i];
    	else
	 		c[i]=0;
    }
  	for(i=1;i<=9;i++)
   		printf("%d",c[i]);
  	out(c);
}

void dif()
{
  	int i,c[10];
  	for(i=1;i<=9;i++)
    {
    	if (a[i]==1 && b[i]==0)
	 		c[i]=1;
    	else
      		c[i]=0;
    }
  	for(i=1;i<=9;i++)
   		printf("%d",c[i]);
   	out(c);
}
