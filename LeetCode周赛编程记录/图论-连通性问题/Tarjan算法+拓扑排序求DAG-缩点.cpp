#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e4 + 5;

int n, m;
int dfn[N], low[N], stk[N], scc[N], cnt, sccnum, top; 
vector<int> f[N];
vector<int> new_f[N];
int a[N];
int scc_sum[N];
int dp[N];
int indegree[N];


void Tarjan(int root){
	if(dfn[root]) return;
	
	dfn[root] = low[root] = ++cnt;
	stk[++top] = root;
	
	for(int v: f[root]){
		if(!dfn[v]){ // 没有访问
			Tarjan(v);
			low[root] = min(low[root], low[v]);
		}
		else if(!scc[v]){ // 如果还在栈内，大概率是联通图的根
			low[root] = min(low[root], dfn[v]);
		}
	}
	
	if(dfn[root] == low[root]){ // 作为联通图的根节点
		sccnum++;
		for(;;){
			int x = stk[top--];
			scc[x] = sccnum;
			scc_sum[sccnum] += a[x];
			if(x == root) break;
		}
	}
}

// 构建SCC的新图
void build_new(){
	for(int u = 1; u <= n; u ++){
		for(int v: f[u]){
			if(scc[u] != scc[v]){
				new_f[scc[u]].push_back(scc[v]);
				indegree[scc[v]] ++;
			}
		}
	}
}

// 拓扑排序
void top_sort(){
	queue<int> q;
	for(int i = 1; i <= sccnum; i ++){
		dp[i] = scc_sum[i];
		if(indegree[i] == 0){
			q.push(i);
		}
	}
	
	while(!q.empty()){
		int u = q.front(); q.pop();
		
		for(int v: new_f[u]){
			dp[v] = max(dp[v], dp[u] + scc_sum[v]);
			indegree[v] --;
			if(indegree[v] == 0){
				q.push(v);
			}
		}
	}
}

void solve(){
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	
	for(int i = 1; i <= m; i ++){
		int u, v;
		cin >> u >> v;
		f[u].push_back(v);
		//f[v].push_back(u);
	}
	
	for(int i = 1; i <= n; i ++){
		Tarjan(i);
	}
	
	// 压缩点成新图
	build_new();
	
	// 拓扑排序求DAG
	top_sort();
	
	int ans = 0;
	for(int i = 1; i <= sccnum; i ++){
		ans = max(ans, dp[i]);
	}
	
	cout << ans;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}