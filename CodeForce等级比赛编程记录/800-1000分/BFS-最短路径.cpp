#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);i++)

void solve(){
	int n,k;
	cin>>n>>k;
	vector<vector<int>> abj(n);
	
	rep(i,n-1){
		int u,v;
		cin>>u>>v;
		u--;v--;
		abj[u].push_back(v);
		abj[v].push_back(u);
	}
	
	//BFS求最短距离
	vector<int> dist(n,-1);
	queue<int> dq;
	dist[0]=0;
	dq.push(0);
	
	while(!dq.empty()){
		int u=dq.front();dq.pop();
		for(int v:abj[u]){
			if(dist[v]==-1){
				dist[v]=dist[u]+1;
				dq.push(v);
			}
		}
	}
	
	for(int i=1;i<n;i++){
		if(dist[i]!=-1&&dist[i]%k==0){
			cout<<dist[i]/k<<" ";
		}
		else cout<<"-1"<<" ";
	}
	
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int t;
	cin>>t;
	while(t--){
		solve();
		cout<<"\n";
	}
}