#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,b) for(int i = a; i <= b; i++)

const int MAX=1e7;

int n,p;
int s[MAX];
int dp[MAX];
int cnt[MAX];

void solve(){
	cin>>n>>p;
	rep(i,1,n){
		cin>>s[i];
	}
	
	//差分
	rep(i,1,p){
		int x,y,z;
		cin>>x>>y>>z;
		dp[x]+=z;dp[y+1]-=z;
	}
	
	//求和
	rep(i,1,n){
		cnt[i]=cnt[i-1]+dp[i];
	}
	
	rep(i,1,n){
		s[i]=s[i]+cnt[i];
	}
	
	int ans=s[1];
	rep(i,2,n){
		ans=min(ans,s[i]);
	}
	
	cout<<ans;
	
	
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}