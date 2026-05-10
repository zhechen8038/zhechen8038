#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;i++)

const int MAX=1e3+5;

int n,m;
int a[MAX];

void solve(){
	cin>>n>>m;
	rep(i,n) cin>>a[i];
	vector<int> dp(m+1,m);
	dp[0]=0;
	
	for(int i=0;i<n;i++){
		for(int j=a[i];j<=m;j++){
			dp[j]=min(dp[j],dp[j-a[i]]+1);
		}
	}
	
	cout<<dp[m];
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
}