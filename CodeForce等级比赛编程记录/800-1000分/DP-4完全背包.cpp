//疯狂的采药，完全背包，数量不限
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+5,M=1e7+5;
int t,m,a[N],b[N],dp[M];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>t>>m;
	for(int i=0;i<m;i++){
		cin>>a[i]>>b[i];
	}
	//memset(dp,0,sizeof(dp));
	for(int i=0;i<m;i++){
		if(a[i]>t) continue;
		for(int j=a[i];j<=t;j++){
			dp[j]=max(dp[j],dp[j-a[i]]+b[i]);
		}
	}
	cout<<dp[t];
	return 0;
}