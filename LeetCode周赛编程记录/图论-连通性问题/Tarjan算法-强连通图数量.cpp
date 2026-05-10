#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e4 + 5;

int n, m;
int dfn[N], low[N], stk[N], scc[N], cnt, sccnum, top; 
vector<int> f[N];
set<int> s[N];
int vis[N];

void Tarjan(int root){
	if(dfn[root]) return;
	
	dfn[root] = low[root] = ++cnt;
	stk[++top] = root;
	
	for(int v: f[root]){
		if(!dfn[v]){ // 没有访问
			Tarjan(v);
			low[root] = min(low[root], low[v]);
		}
		else if(!scc[v]){ // 如果还在栈内，大概率是联通图的根
			low[root] = min(low[root], dfn[v]);
		}
	}
	
	if(dfn[root] == low[root]){ // 作为联通图的根节点
		sccnum++;
		for(;;){
			int x = stk[top--];
			scc[x] = sccnum;
			s[sccnum].insert(x);
			if(x == root) break;
		}
	}
}

void solve(){
	cin >> n >> m;
	for(int i = 1; i <= m; i ++){
		int u, v;
		cin >> u >> v;
		f[u].push_back(v);
		//f[v].push_back(u);
	}
	
	for(int i = 1; i <= n; i ++){
		Tarjan(i);
	}
	
	cout << sccnum << "\n";
	
	int count = 0;
	for(int i = 1; i <= n; i ++){
		int start = scc[i];
		if(!vis[start]){
			count ++;
			vis[start] = 1;
			for(int x: s[start]){
				cout << x << " ";
			}
			cout << "\n";
		}
		if(count == sccnum) break;
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}