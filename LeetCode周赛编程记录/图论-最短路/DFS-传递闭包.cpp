#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 105;
const int MOD = 100003;

int n;
vector<int> f[N];
int b[N][N];
int vis[N];

void dfs(int s, int u){
	for(int v: f[u]){
		if(vis[v]) continue;
		vis[v] = 1;
		b[s][v] = 1;
		dfs(s, v);
	}
}

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n; j ++){
			int w;
			cin >> w;
			if(w == 1){
				f[i].push_back(j);
				b[i][j] = 1;
			}
		}
	}
	
	for(int i = 1; i <= n; i ++){
		fill(vis, vis+n+1, 0);
		dfs(i, i);
	}
	
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n; j ++){
			cout << b[i][j] << " ";
		}
		cout << "\n";
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}