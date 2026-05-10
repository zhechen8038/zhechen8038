#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 500005;
const int LOG = 20;

int n, m, s;
vector<int> f[N];
int p[N][LOG+1], dep[N];
int vis[N];


void dfs(int x, int d){
	vis[x] = 1;
	dep[x] = d;
	
	for(int v: f[x]){
		if(vis[v]) continue;
		p[v][0] = x;
		dfs(v, d + 1);
	}
}

int lca(int a, int b){
	if(dep[a] < dep[b]) swap(a, b);
	
	// 1. 把 a 提升到和 b 同一深度
	for(int k = LOG; k >= 0; k --){
		if(dep[a] - (1<<k) >= dep[b]){
			a = p[a][k];
		}
	} 
	
	if(a == b) return a;
	
	// 2. 同时往上跳
	for(int k = LOG; k >= 0; k --){
		if(p[a][k] != p[b][k]){
			a = p[a][k];
			b = p[b][k];
		}
	}
	
	return p[a][0];
}

void solve(){
	cin >> n >> m >> s;
	for(int i = 0; i < n - 1; i ++){
		int u, v;
		cin >> u >> v;
		f[u].push_back(v);
		f[v].push_back(u);
	}
	
	p[s][0] = s;
	dfs(s, 1);
	
	// 预处理倍增表
	for(int k = 1; k <= LOG; k ++){
		for(int i = 1;i <= n; i ++){
			p[i][k] = p[p[i][k - 1]][k - 1];
		}
	}
	
	for(int i = 0; i < m; i ++){
		int u, v;
		cin >> u >> v;
		int ans = lca(u, v);
		cout << ans << "\n";
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}