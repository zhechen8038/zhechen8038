#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=1;i<=n;i++)

const int MAX=1e4+5;
const int MOD=1e9+7;

int n,m;
int a[MAX];
int dp[MAX];

void solve(){
	cin>>n>>m;
	rep(i,n) cin>>a[i];
	
	dp[0]=1;
	
	rep(i,n){
		for(int j=m;j>=a[i];j--){
			dp[j]+=dp[j-a[i]];
		}
	}
	
	cout<<dp[m];
	
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}