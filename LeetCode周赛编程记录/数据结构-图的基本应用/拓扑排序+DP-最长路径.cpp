#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,b) for(int i=a;i<=b;i++)

const int MAXN = 1505;
const int INF = 1e9;

int n,m;
vector<pair<int,int>> g[MAXN];//邻接表
ll indegree[MAXN];//入度
ll dp[MAXN];//以当前节点为结尾的最长路径

void solve(){
	cin>>n>>m;
	
	rep(i,1,m){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		indegree[v]++;
	}
	
	//拓扑排序
	queue<int> q;
	fill(dp + 1, dp + n + 1, -INF);
    dp[1] = 0;
    
	rep(i,1,n){
		if(!indegree[i]){//入度为0进队
			q.push(i);
		}
	}
	
	while(!q.empty()){
		int u=q.front();q.pop();
		
		for(pair<int,int>& p:g[u]){
			int v=p.first;
			ll w=p.second;
			dp[v]=max(dp[v],dp[u]+w);//状态转移
			indegree[v]--;
			if(!indegree[v]){
				q.push(v);
			}
		}
	}
	
	int ans=dp[n];
	if(ans==-INF) cout<<-1;
	else cout<<ans;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	solve();
}