#include<stdio.h>
 int main()
 {
 	int a[10],b[10],c[10],i,j,t,n1,n2;
 	
 	printf("\nEnter limit of array 1 : ");
 	scanf("%d",&n1);
 	
 	for(i=0;i<n1;i++)
 		scanf("%d",&a[i]);
 	
 	printf("\nEnter limit of array 2 : ");
 	scanf("%d",&n2);
 	
 	for(i=0;i<n2;i++)
 		scanf("%d",&b[i]);
 		
 			
 	for(i=0;i<n1;i++)
 		c[i]=a[i];
 	for(i=0;i<n2;i++)
 		c[i+n1]=b[i];

 		
 	for(i=0;i<(n1+n2)-1;i++)
	 	for(j=i+1;j<n1+n2;j++)
		 	if(c[j]<c[i])
			 {
			 	t=c[i];
			 	c[i]=c[j];
			 	c[j]=t;
				 }		
 	
 	for(i=0;i<n1+n2;i++)
 		printf("\t%d",c[i]);
 }
