#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 6e3 + 1;

int n, a[N];
vector<int> g[N];
int dp[N][2];
int indegree[N];

void dfs(int u){
	dp[u][0] = 0; // 不选自己
	dp[u][1] = a[u]; // 选自己
	
	for(int v: g[u]){
		dfs(v);
		dp[u][0] += max(dp[v][0], dp[v][1]); // 不选自己，可以选和不选直接后代
		dp[u][1] += dp[v][0]; // 选自己，不能选直接后代
	}
}
void solve(){
	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	
	for(int i = 1; i <= n - 1; i ++){
		int u, p;
		cin >> u >> p;
		g[p].push_back(u);
		indegree[u] ++;
	}
	
	int root;
	for(int i = 1; i <= n; i ++){
		if(indegree[i] == 0){
			root = i;
			break;
		}
	}
	
	dfs(root);
	
	int ans = max(dp[root][1], dp[root][0]);
	cout << ans;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}