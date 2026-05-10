#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1505;

int n, dp[N][2];
vector<int> g[N];

void dfs(int u, int p){
	dp[u][0] = 0;
	dp[u][1] = 1;
	
	for(int v: g[u]){
		if(v == p) continue;
		dfs(v, u);
		dp[u][0] += dp[v][1]; // u不放，v必放
		dp[u][1] += min(dp[v][1], dp[v][0]); // u放，v可放可不放
	}
}

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i ++){
		int u, k;
		cin >> u >> k;
		for(int j = 1; j <= k; j ++){
			int v;
			cin >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
	}
	
	dfs(0, -1);
	
	int ans = min(dp[0][1], dp[0][0]);
	cout << ans;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}