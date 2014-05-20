#include <iostream>
#include <stdio.h>

using namespace std;

void merge(int b[],int l,int mid,int u)
{
	int t[100002]={};
	int k=0,i;
	int j=mid;

	while(i<mid&&j<=u)
	{
		if(b[i]<=b[j])
			t[k++]=b[i++];
		else
			t[k++]=b[j++];

	}
	while(i<mid)
		t[k++]=b[i++];
	while(j<=u)
		t[k++]=b[j++];
	for(int i=l;i<=u;i++)
		b[i]=t[i-l];
}
void ms(int b[],int l,int u)
{
	if(l<u)
	{
		int mid=(l+u)/2;
		ms(b,l,mid);
		ms(b,mid+1,u);
		merge(b,l,mid+1,u);
	}
}

int main() 
{
	int b[100002]={};

	int n;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
		scanf("%d",b[i]);
		
	ms(b,0,n-1);

	for(int i=0;i<n;i++)
		printf("%d ",b[i]);

	return 0;
}
