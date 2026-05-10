#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;
const int INF = 2147483647;

int n, m, s;
int dp[N];
vector<pair<int, int>> f[N];

void solve(){
	cin >> n >> m >> s;
	for(int i = 0; i < m; i ++){
		int u, v, w;
		cin >> u >> v >> w;
		f[u].push_back({v, w});
	}
	
	fill(dp, dp + n + 1, INF);
	dp[s] = 0;
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, s});
	
	while(!pq.empty()){
		auto [dis, u] = pq.top(); pq.pop();
		if(dis > dp[u]) continue; // u节点最短路已经确定就跳过
		for(auto [v, w] : f[u]) {
            if(dp[v] > dp[u] + w) {
                dp[v] = dp[u] + w;
                pq.push({dp[v], v});
            }
        }
	}
	
	for(int i = 1; i <= n; i++) {
        if(dp[i] == INF) cout << "INF ";
        else cout << dp[i] << " ";
    }
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}