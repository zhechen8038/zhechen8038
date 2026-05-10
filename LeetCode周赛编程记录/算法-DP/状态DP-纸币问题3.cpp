#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=1;i<=n;i++)

const int MAX=1e4+5;
const ll MOD=1e9+7;
int n,w;
int a[MAX];
ll dp[MAX];

void solve(){
	cin>>n>>w;
	rep(i,n) cin>>a[i];
	
	dp[0]=1;
	rep(i,w){
		for(int j=1;j<=n;j++){
			if(a[j]<=i){
				dp[i]=(dp[i]+dp[i-a[j]])%MOD;
			}
		}
	}
	
	cout<<dp[w]%MOD;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
}