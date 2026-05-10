#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;i++)

void solve(){
	int n;
	cin>>n;
	vector<vector<int>> a(2,vector<int>(n));
	rep(i,2) rep(j,n) cin>>a[i][j];
	
	int mx;
	ll sum=0;
	
	rep(i,n){
		int val=min(a[0][i],a[1][i]);
		sum+=max(a[0][i],a[1][i]);
		
		if(i==0) mx=val;
		else mx=max(mx,val);
	} 
	
	sum+=mx;
	cout<<sum;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int t;
	cin>>t;
	
	while(t--){
		solve();
		cout<<"\n";
	}
}