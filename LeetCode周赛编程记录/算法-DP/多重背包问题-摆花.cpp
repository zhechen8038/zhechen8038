#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=1;i<=n;i++)

const int MAX=105;
const int MOD=1e6+7;

int n,m;
int a[MAX];
int dp[MAX];

void solve(){
	cin>>n>>m;
	rep(i,n) cin>>a[i];
	
	dp[0]=1;
	
	for(int i = 1; i <= n; i ++){
		for(int j = m; j >= 0; j --){
			for(int k = 1; k <= a[i] && k <= j; k ++)
				dp[j] = (dp[j] + dp[j - k]) % MOD;
		}
	}
	
	cout<<dp[m]%MOD;
	
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}