#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;i++)

void solve(){
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	rep(i,n) cin>>a[i];
	
	while(m--){
		int x;
		cin>>x;
		cout<<a[x-1]<<"\n";
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	solve();
}