#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 16005;
const ll INF = 2147483647;

int n, a[N];
ll ans, dp[N];
vector<int> g[N];

void dfs(int u, int p){
	dp[u] = a[u];
	for(int v: g[u]){
		if(v == p) continue;
		dfs(v, u);
		if(dp[v] > 0) dp[u] += dp[v];
	}
	
	ans = max(ans, dp[u]);
}

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	
	for(int i = 1; i <= n - 1; i ++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	ans = -INF;
	
	dfs(1, -1);
	
	cout << ans;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}