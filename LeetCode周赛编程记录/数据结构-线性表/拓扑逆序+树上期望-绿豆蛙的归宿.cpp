#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;

int n, m;
vector<pair<int,int>> g[N];
int indegree[N], outdegree[N];
double E[N];

void solve(){
	cin >> n >> m;
	for(int i = 1; i <= m; i ++){
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		outdegree[u] ++;
		indegree[v] ++;
	}
	
	queue<int> q;
	for(int i = 1; i <= n; i ++){
		if(indegree[i] == 0) q.push(i);
	}
	
	stack<int> s;
	while(!q.empty()){
		int u = q.front(); q.pop();
		s.push(u);
		for(auto [v, w]: g[u]){
			if(--indegree[v] == 0)
				q.push(v);
		}
	}
	
	while(!s.empty()){
		int u = s.top(); s.pop();
		if(outdegree[u] == 0){
			E[u] = 0.00;
			continue;
		}
		
		double sum = 0;
		for(auto [v, w]: g[u]){
			sum += (double)w + E[v];
		}
		
		E[u] = sum / (double)outdegree[u];
	}
	
	printf("%.2f",E[1]);
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}