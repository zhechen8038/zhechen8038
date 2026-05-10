#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 20005;

int n, m;
int dfn[N], low[N], cnt; 
vector<int> f[N];
set<int> cutpoints; // 割点

void Tarjan(int u, int p){
	dfn[u] = low[u] = ++cnt;
	int child = 0; // 子树数量
	
	for(int v: f[u]){
		if(!dfn[v]){
			child++;
			Tarjan(v, u);
			low[u] = min(low[u], low[v]);
			
			// 情况 2：u 不是根 && 存在子节点 v 满足 low[v] >= dfn[u]
			if(p != -1 && low[v] >= dfn[u]){
				cutpoints.insert(u);
			}
		}
		else if(v != p){ // 回边（忽略父亲）
			low[u] = min(low[u], dfn[v]);
		}
	}
	
	// 情况 1：u 是根节点 && 有两个以上独立子树
	if(p == -1 && child > 1){
		cutpoints.insert(u);
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
	
	// 输出割点
	cout << cutpoints.size() << "\n";
	for(int x: cutpoints){
		cout << x << " ";
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}