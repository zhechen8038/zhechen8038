//装箱问题
#include<bits/stdc++.h>
using namespace std;
int main(){
	int V,n;
	cin>>V>>n;
	int v[n+1];
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	
	int dp[V+1];
	memset(dp,0,sizeof(dp));
	
	for(int i=0;i<n;i++){
		for(int j=V;j>=v[i];j--){
			dp[j]=max(dp[j],dp[j-v[i]]+v[i]);
		}
	}
	cout<<V-dp[V];
	return 0;
}