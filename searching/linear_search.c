#include<stdio.h>
int main()
{
	int n,key,i;
	printf("enter the size of array: ");
	scanf("%d",&n);
	int a[n];
	printf("enter %d numbers to store in array: ",n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("enter the key: ");
	scanf("%d",&key);
	
	for(i=0;i<n;i++)
	{
	if(a[i]==key)
	{
	printf("the key %d is found in the index %d",key,i);
	break;
}
}
	
	if(i==n)
	printf("key not found");
}
