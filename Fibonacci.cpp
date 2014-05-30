#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;

int main() {
	char ss[4801][1002]={};
	ss[0][0]='0';
	ss[1][0]='1';
	int l=0;
	for(int j=2;j<=4800;j++)
	{
		int c=0,a1,a2;
		for(int i=0;i<=l;i++)
		{
			a1=ss[j-1][i]==0?0:ss[j-1][i]-'0';
			a2=ss[j-2][i]==0?0:ss[j-2][i]-'0';
			ss[j][i]=(a1+a2+c)%10+'0';
			c=(a1+a2+c)/10;
		}
		if(c!=0)
		{
			l++;
			if(l>=1001)
				break;
			ss[j][l]=c+'0';
		}
	}
	vector <string> fib;
	for(int i=0;i<=4800;i++)
		fib.push_back(ss[i]);
	sort(fib.begin(),fib.end());
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char s[1001]={};
		scanf("%s",s);
		for(int i=0;i<strlen(s)/2;i++)
			swap(s[i],s[strlen(s)-1-i]);
		if(binary_search(fib.begin(),fib.end(),s))
			printf("YES\n");
		else
			printf("NO\n");
	}	
	return 0;
}
