#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;

int main() {
	char a[1000]={};
	char b[1000]={};
	scanf("%s %s",a,b);
	int m=strlen(a),n=strlen(b);
	int ans[1000][1000]={};
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			if(a[i-1]==b[j-1])
				ans[i][j]=1+ans[i-1][j-1];
			else
				ans[i][j]=max(ans[i-1][j],ans[i][j-1]);
	printf("%d\n",ans[m][n]);
	return 0;
}
