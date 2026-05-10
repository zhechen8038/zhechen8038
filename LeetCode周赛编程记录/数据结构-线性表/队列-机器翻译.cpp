#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;i++)

void solve(){
	int m,n;
	cin>>m>>n;
	vector<int> a(n);
	vector<bool> visited(1001,false);
	rep(i,n) cin>>a[i];
	
	queue<int> q;
	
	int ans=0;
	
	rep(i,n){
		if(!visited[a[i]]){
			if((int)q.size()==m){
				int x=q.front();q.pop();
				visited[x]=false;
			}
			q.push(a[i]);
			visited[a[i]]=true;
			
			ans++;
		}
	}
	
	cout<<ans;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	solve();
}