#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=1;i<=n;i++)

void solve(){
	int n,a,b;
	cin>>n>>a>>b;
	vector<int> k(n+1);
	rep(i,n) cin>>k[i];
	
	vector<int> ans(n+1,-1);
	vector<int> visited(n+1,0);
	queue<int> q;
	
	ans[a]=0;
	visited[a]=1;
	q.push(a);
	
	while(!q.empty()){
		int cur=q.front();
		q.pop();
		
		vector<int> next={cur-k[cur],cur+k[cur]};
		for(int i=0;i<2;i++){
			if(next[i]>=1&&next[i]<=n&&!visited[next[i]]){
				ans[next[i]]=ans[cur]+1;
				visited[next[i]]=1;
				q.push(next[i]);
			}
		}
	}
	
	cout<<ans[b];
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int t=1;
	while(t--){
		solve();
		cout<<"\n";
	}
}