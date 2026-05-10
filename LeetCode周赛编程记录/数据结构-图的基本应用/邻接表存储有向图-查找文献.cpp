#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,b) for(int i=a;i<=b;i++)

const int MAX=1e5+1;

struct node{
	vector<int> t;
	int size;
};

int n,m;
vector<node> g(MAX);//邻接表
vector<int> visited(MAX,0);
queue<int> q;

void dfs(int x,int cnt){
	visited[x]=1;
	cout<<x<<" ";
	if(cnt==n||!g[x].size){
		return;
	}
	
	rep(i,0,g[x].size-1){
		if(!visited[g[x].t[i]]){
			dfs(g[x].t[i],cnt+1);
		}
	}
}

void bfs(int x){
	q.push(x);
	visited[x]=1;
	
	while(!q.empty()){
		int cur=q.front();
		q.pop();
		cout<<cur<<" ";
		rep(i,0,g[cur].size-1){
			if(!visited[g[cur].t[i]]){
				visited[g[cur].t[i]]=1;
				q.push(g[cur].t[i]);
			}
		}
	}
}

void solve(){
	cin>>n>>m;
	
	rep(i,1,m){
		int u,v;
		cin>>u>>v;
		g[u].t.push_back(v);
		g[u].size++;
	}
	
	rep(i,1,n) sort(g[i].t.begin(),g[i].t.end());
	
	dfs(1,0);
	cout<<"\n";
	fill(visited.begin(),visited.end(),0);
	bfs(1);
	
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	solve();
}