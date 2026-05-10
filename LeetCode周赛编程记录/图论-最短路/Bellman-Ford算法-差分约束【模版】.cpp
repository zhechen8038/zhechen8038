#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 6000;
const int INF = 2147483647;

int n, m;
int dp[N];
vector<pair<int, int>> f[N];

bool Bellman_Ford(int s){
	fill(dp, dp + n + 1, INF);
	dp[s] = 0;
	
	// 松弛阶段
	for(int i = 0; i < n - 1; i ++){
		bool jug = false;
		for(int u = 0; u <= n; u ++){
			if(dp[u] == INF) continue;// 未到达的节点跳过
			for(auto [v, w]: f[u]){
				if(dp[v] > dp[u] + w){
					dp[v] = dp[u] + w;
					jug = true;
				}
			}
		}
		if(!jug) break; // 提前终止
	}
	
	// 检测负权环
	for(int u = 0; u <= n; u ++){
		if(dp[u] == INF) continue;
		for(auto [v, w]: f[u]){
			if(dp[v] > dp[u] + w){
				return false; // 存在负环
			}
		}
	}
	
	return true;
}

void solve(){
	cin >> n >> m;
	
	for(int i = 0; i < m; i ++){
		int u, v, w;
		cin >> u >> v >> w;
		f[v].push_back({u, w});
	}
	
	// 添加超级源点0
    for(int i = 1; i <= n; i++){
        f[0].push_back({i, 0});
    }
    
	if(Bellman_Ford(0)){
		// cout << "NO\n";
		for(int u = 1; u <= n; u ++){
			cout << dp[u] << " ";
		}
	}
	
	else cout << "NO";
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}