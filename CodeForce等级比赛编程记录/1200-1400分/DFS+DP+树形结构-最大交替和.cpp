#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;i++)

int n;
vector<ll> a;
vector<vector<int>> abj;
//f表示最大威胁度，g表示最小威胁度
vector<ll> f,g;
vector<ll> ans;

void dfs(int u,int p){
	f[u]=a[u];
	g[u]=a[u];
	
	if(p!=-1){
		f[u]=max(f[u],a[u]-g[p]);
		g[u]=min(g[u],a[u]-f[p]);
	}
	
	ans[u]=f[u];
	for(int v:abj[u]){
		if(v==p) continue;//循环到底，开始回头，即儿子节点等于父亲节点
		dfs(v,u);
	}
}

void solve(){
	cin>>n;
	a.resize(n);
	abj.assign(n,{});//二维初始化
	f.resize(n);
	g.resize(n);
	ans.resize(n);
	
	rep(i,n) cin>>a[i];
	rep(i,n-1){
		int u,v;
		cin>>u>>v;
		u--;v--;
		abj[u].push_back(v);
		abj[v].push_back(u);
	}
	
	dfs(0,-1);
	
	rep(i,n) cout<<ans[i]<<" ";
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int t;
	cin>>t;
	
	while(t--){
		solve();
		cout<<"\n";
	}
}