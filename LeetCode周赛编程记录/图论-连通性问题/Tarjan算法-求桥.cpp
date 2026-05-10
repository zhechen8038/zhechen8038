#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 20005;

int n, m;
int dfn[N], low[N], cnt; 
vector<int> f[N];
vector<pair<int,int>> bridges; // 存桥

void Tarjan(int u, int p){
	dfn[u] = low[u] = ++cnt;
	for(int v: f[u]){
		if(!dfn[v]){
			Tarjan(v, u);
			low[u] = min(low[u], low[v]);
			if(low[v] > dfn[u]){
				// (u,v) 是桥
				bridges.push_back({u, v});
			}
		}
		else if(v != p){ // 回边（忽略父亲）
			low[u] = min(low[u], dfn[v]);
		}
	}
}

void solve(){
	cin >> n >> m;
	for(int i = 1; i <= m; i ++){
		int u, v;
		cin >> u >> v;
		f[u].push_back(v);
		f[v].push_back(u);
	}
	
	for(int i = 1; i <= n; i ++){
		if(!dfn[i]) Tarjan(i, -1);
	}
	
	// 输出桥
	sort(bridges.begin(), bridges.end());
	for(auto [u, v]: bridges){
		cout << u << " " << v << "\n";
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}