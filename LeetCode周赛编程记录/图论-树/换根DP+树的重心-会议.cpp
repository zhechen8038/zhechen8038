#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 50005;
const int INF = 1e8;

int n;
vector<int> f[N];
int dp[N], sz[N]; // sz[x] 子树大小, dp[x] 到所有点的距离和


void dfs1(int u, int p){ // 初创一个情况
	dp[u] = 0;
	sz[u] = 1;
	for(int v: f[u]){
		if(v == p) continue;
		dfs1(v, u);
		sz[u] += sz[v];
		dp[u] += dp[v] + sz[v];
	}
}

void dfs2(int u, int p){
	for(int v: f[u]){
		if(v == p) continue;
		// 从 u 换根到 v
        dp[v] = dp[u] + (n - 2 * sz[v]); // 上移dp[v]，v子树节点全体减一，下移dp[u]，其他节点全体加一。
		dfs2(v, u);
	}
}


void solve(){
	cin >> n;
	for(int i = 0; i < n - 1; i ++){
		int u, v;
		cin >> u >> v;
		f[u].push_back(v);
		f[v].push_back(u);
	}
	
	dfs1(1, 0);  // 任选 1 为根
    dfs2(1, 0);
    
	int cur = dp[1], index = 1;
	
	for(int i = 2; i <= n; i ++){
		if(dp[i] < cur){
			cur = dp[i];
			index = i;
		}
	}
	
	cout << index << " " << cur;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}