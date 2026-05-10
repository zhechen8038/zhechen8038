//美化绿植问题
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int h[n+1];
	for(int i=0;i<n;i++){
		cin>>h[i];
	}
	
	int dp[n+1]={1};
	int ans=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(h[j]<h[i]) dp[i]=max(dp[i],dp[j]+1);
		}
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
	
}