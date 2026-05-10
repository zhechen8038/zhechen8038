#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,b) for(int i=a;i<=b;i++)

const int MAX=1e6;
const int MOD=80112002;

int n,m;
vector<int> g[MAX];//邻接表
ll indegree[MAX];//入度
ll outdegree[MAX];//出度
ll dp[MAX];//dp[i]表示以i结尾的最大食物链条数

void solve(){
	cin>>n>>m;
	
	rep(i,1,m){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		indegree[v]++;
		outdegree[u]++;
	}
	
	//拓扑排序
	queue<int> q;
	rep(i,1,n){
		if(!indegree[i]){//入度为0进队
			q.push(i);
			dp[i]=1;
		}
	}
	
	while(!q.empty()){
		int u=q.front();q.pop();
		
		for(int v:g[u]){
			dp[v]=(dp[v]+dp[u])%MOD;//状态转移
			indegree[v]--;
			if(!indegree[v]){
				q.push(v);
			}
		}
	}
	
	ll ans=0;
	rep(i,1,n){
		//找汇点
		if(!outdegree[i]){
			ans=(ans+dp[i])%MOD;
		}
	}
	
	cout<<ans;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	solve();
}