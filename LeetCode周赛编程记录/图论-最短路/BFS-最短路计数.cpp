#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 1;
const int MOD = 100003;

int n, m;
vector<int> f[N];
int dis[N], cnt[N];
void bfs(int s){
	fill(dis, dis+n+1, -1);
	fill(cnt, cnt+n+1, 0);
	
	dis[s] = 0;
	cnt[s] = 1;
	
	queue<int> q;
	
	q.push(s);
	while(!q.empty()){
		int u = q.front(); q.pop();
		for(int v: f[u]){
			if(dis[v] == -1){ // 第一次到达
				dis[v] = dis[u] + 1;
				cnt[v] = cnt[u];
				q.push(v);
			}
			else if(dis[v] == dis[u] + 1){ // 找到另一条路
				cnt[v] += cnt[u];
				cnt[v] %= MOD;
			}
		}
	}
}
void solve(){
	cin >> n >> m;
	for(int i = 0; i < m; i ++){
		int u, v;
		cin >> u >> v;
		f[u].push_back(v);
		f[v].push_back(u);
	}
	
	bfs(1);
	
	for(int i = 1; i <= n; i ++){
		cout << cnt[i] << "\n";
	}
	
	
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}