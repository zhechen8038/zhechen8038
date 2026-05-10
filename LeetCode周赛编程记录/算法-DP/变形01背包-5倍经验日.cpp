#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=1;i<=n;i++)

const int MAX=1e3+5;
const int MOD=1e9+7;

int n,x;
int a[MAX],b[MAX],c[MAX];
ll dp[MAX],new_dp[MAX];

void solve(){
	cin>>n>>x;
	rep(i,n){
		cin>>a[i]>>b[i]>>c[i];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=0;j<=x;j++) new_dp[j]=dp[j]; // 旧 -> 新
		for(int j=0;j<=x;j++){
			new_dp[j]=max(new_dp[j],dp[j]+a[i]);
			
			if(j>=c[i]){
				new_dp[j]=max(new_dp[j],dp[j-c[i]]+b[i]);
			}
		}
		for(int j=0;j<=x;j++) dp[j]=new_dp[j]; // 新 -> 新
	}
	
	cout<<dp[x]*5;
	
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}