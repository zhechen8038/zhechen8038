#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,b) for(int i=a;i<=b;i++)

const int MAX=1e4+1;

int n;
int t[MAX];
vector<int> g[MAX];//邻接表
int indegree[MAX];//入度
int dp[MAX];

void solve(){
	cin>>n;
	
	rep(i,1,n){
		int id;
		cin>>id>>t[id];
		while(1){
			int x;
			cin>>x;
			if(x==0) break;
			g[x].push_back(id);
			indegree[id]++;
		}
	}
	
	//拓扑排序
	queue<int> q;
	rep(i,1,n){
		if(!indegree[i]){//入度为0进队
			q.push(i);
			dp[i]=t[i];
		}
	}
	
	while(!q.empty()){
		int u=q.front();q.pop();
		
		for(int v:g[u]){
			dp[v]=max(dp[v],dp[u]+t[v]);//状态转移
			indegree[v]--;
			if(!indegree[v]){
				q.push(v);
			}
		}
	}
	
	int ans=0;
	rep(i,1,n){
		ans=max(ans,dp[i]);
	}
	
	cout<<ans;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	solve();
}