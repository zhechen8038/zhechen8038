#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 305;
const int NEG = -1e9;

int n, m, s[N];
vector<int> g[N];
vector<vector<int>> dp(N, vector<int>(N, NEG));
int sz[N];

void dfs(int u){
	dp[u][0] = 0;
	dp[u][1] = s[u];
	sz[u] = 1;
	for(int v: g[u]){
		dfs(v);
		
		for(int j = min(m + 1, sz[u] + sz[v]); j >= 1; j --){
			for(int k = 0; k <= min(j - 1, sz[v]); k ++){
				if(dp[u][j - k] == NEG || dp[v][k] == NEG) continue;
				dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[v][k]);
			}
		}
		
		sz[u] = min(m + 1, sz[u] + sz[v]);
	}
}

void solve(){
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		int k;
		cin >> k >> s[i];
		g[k].push_back(i);
	}
	
	s[0] = 0;//虚根
	
	dfs(0);
	
	cout << dp[0][m + 1];
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}