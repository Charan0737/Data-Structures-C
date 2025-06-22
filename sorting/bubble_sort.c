#include<stdio.h>
int main()
{
	int n,i,j,temp,swapped=0;
	printf("enter the size of array: ");
	scanf("%d",&n);
	int a[n];
	printf("enter %d numbers to store in array: ",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
    }
    
    for(i=0;i<n-1;i++)
    {
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				swapped=1;
			}
		}
	if(swapped==0)
	{
		break;
	}
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}

		
		
    
    
    
    


