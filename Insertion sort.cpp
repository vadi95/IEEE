#include <iostream>
#include <stdio.h>
using namespace std;

void is(int arr[],int n)
{
	for(int i=1;i<n;i++)
	{
		int temp=arr[i];
		int j;
		
		for(j=i-1;j>=0;j--)
		{
			if(arr[j]>temp)	
				arr[j+1]=arr[j];
			else	
				break;
		}		
		arr[j+1]=temp;
	}

}

int main() {
	int arr[100002]={};
	
	int n;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	
	is(arr,n);
	
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
	return 0;
}
