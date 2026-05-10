#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=1;i<=n;i++)

const int MAX=1e3+5;

int n;
int a[MAX][MAX];
int dp[MAX][MAX];

void solve(){
	cin>>n;
	rep(i,n){
		rep(j,i) cin>>a[i][j];
	}
	
	rep(i,n){
		rep(j,i){
			dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+a[i][j];
		}
	}
	
	int ans=0;
	rep(i,n){
		ans=max(ans,dp[n][i]);
	}
	cout<<ans;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
}