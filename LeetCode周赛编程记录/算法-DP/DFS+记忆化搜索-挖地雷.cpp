#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=1;i<=n;i++)

const int MAX=25;
const int MOD=1e9+7;
int n;
int a[MAX];
int dp[MAX];
vector<int> f[MAX];
vector<int> s[MAX];
int vis[MAX];

void dfs(int x){
	if(vis[x]) return;
	vis[x]=1;
	dp[x]=a[x];
	s[x].push_back(x);
	
	int mx=0,index=-1;
	for(int v:f[x]){
		dfs(v);
		if(mx<dp[v]){
			mx=dp[v];
			index=v;
		}
	}
	if(index!=-1){
		dp[x]+=mx;
		for(int nxt:s[index]){
			s[x].push_back(nxt);
		}
	}
}
void solve(){
	cin>>n;
	rep(i,n){
		cin>>a[i];
	}
	
	rep(i,n-1){
		for(int j=i+1;j<=n;j++){
			int x;
			cin>>x;
			if(x) f[i].push_back(j);
		}
	}
	
	for(int i=n;i>=1;i--){
		dfs(i);
	}
	
	int ans=0;
	int index;
	rep(i,n){
		if(ans<dp[i]){
			index=i;
			ans=dp[i];
		}
	}
	for(int x:s[index]){
		cout<<x<<" ";
	}
	cout<<"\n";
	cout<<ans;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}