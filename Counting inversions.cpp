#include <iostream>
#include <stdio.h>

using namespace std;

long long int merge(int b[],int l,int mid,int u)
{
	int t[100002]={};
	long long int in=0,i;
	int k=0;
	int j=mid;
	i=l;
	while(i<mid&&j<=u)
	{
		if(b[i]<=b[j])
			t[k++]=b[i++];
		else
		{
			in+=mid-i;
			t[k++]=b[j++];
		}
	}
	while(i<mid)
		t[k++]=b[i++];
	while(j<=u)
		t[k++]=b[j++];
	for(int i=l;i<=u;i++)
		b[i]=t[i-l];
	return in;
}
long long int ms(int b[],int l,int u)
{
	long long int in=0;

	if(l<u)
	{
		int mid=(l+u)/2;
		in=ms(b,l,mid);
		in+=ms(b,mid+1,u);
		in+=merge(b,l,mid+1,u);
	}
	return in;
}

int main() 
{
	int b[100002]={};

	int n;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
		scanf("%d",b[i]);
		
	printf("No of inversions: %lld",ms(b,0,n-1));

	return 0;
}
