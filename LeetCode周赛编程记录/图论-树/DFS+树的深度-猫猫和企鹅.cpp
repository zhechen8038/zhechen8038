#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 +5;

int n, d;
vector<int> f[N];
int vis[N];
int dis[N];

void dfs(int x, int dep){
	if(vis[x]) return;
	vis[x] = 1;
	
	for(int v: f[x]){
		dfs(v, dep + 1);
	}
	
	dis[x] = dep;
}
void solve(){
	cin >> n >> d;
	for(int i = 0; i < n - 1; i ++){
		int u, v;
		cin >> u >> v;
		f[u].push_back(v);
		f[v].push_back(u);
	}
	
	dfs(1, 0);
	
	int ans = 0;
	for(int i = 2; i <= n; i ++){
		if(dis[i] <= d) ans ++;
	}
	
	cout << ans;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}