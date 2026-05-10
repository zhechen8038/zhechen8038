//0-1背包问题,数量有限
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int w[n+1],p[n+1];
	for(int i=0;i<n;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>p[i];
	}
	
	int dp[m+1];
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++){
		for(int j=m;j>=w[i];j--){
			dp[j]=max(dp[j],dp[j-w[i]]+p[i]);
		} 
	}
	cout<<dp[m];
	return 0;
	
}