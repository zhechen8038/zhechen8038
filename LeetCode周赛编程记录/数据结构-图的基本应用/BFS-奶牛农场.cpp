#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,b) for(int i=a;i<=b;i++)

const int MAXN = 1505;

int k,n,m;

vector<int> g[MAXN];//邻接表
int cnt[MAXN];//牧场所能容纳的奶牛数
int cowstart[MAXN];

void bfs(int start){
	vector<int> vis(n+1,0);
	
	queue<int> q;
	q.push(start);
	vis[start]=1;
	
	while(!q.empty()){
		int u=q.front();
		q.pop();
		cnt[u]++;
		
		for(int v:g[u]){
			if(!vis[v]){
				vis[v]=1;
				q.push(v);
			}
		}
	}
	
}

void solve(){
	cin>>k>>n>>m;
	
	rep(i,1,k){
		cin>>cowstart[i];
	}
	
	rep(i,1,m){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
	}
	
	//思路：对每头奶牛bfs，每次让奶牛访问能够访问的农场
	rep(i,1,k){
		bfs(cowstart[i]);
	}
	
	int ans=0;
	rep(i,1,n){
		if(cnt[i]==k) ans++;
	}
	
	cout<<ans;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	solve();
}