//最长公共子序列问题
#include<bits/stdc++.h>
using namespace std;
int main(){
	string x,y;
	cin>>x>>y;
	int m=x.size(),n=y.size();
	int dp[m+1][n+1];
	int i,j;
	for(i=0;i<=m;i++){
		dp[i][0]=0;
	}
	for(j=0;j<=n;j++){
		dp[0][j]=0;
	}
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			if(x[i-1]==y[j-1]){
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	cout<<dp[m][n]<<endl;
	return 0;
}