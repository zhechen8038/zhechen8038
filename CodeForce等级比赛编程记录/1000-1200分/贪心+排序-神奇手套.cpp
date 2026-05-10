#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<n ;i++)

bool cmp(const pair<int,int>& p1,const pair<int,int>& p2){
	return min(p1.first,p1.second)>min(p2.first,p2.second);
}

void solve(){
	int n,k;
	cin>>n>>k;
	vector<pair<int,int>> a(n);
	rep(i,n) cin>>a[i].first;
	rep(i,n) cin>>a[i].second;
	
	sort(a.begin(),a.end(),cmp);
	
	ll sum=0;
	
	rep(i,n){
		sum+=max(a[i].first,a[i].second);
	}
	
	rep(i,k-1){
		sum+=min(a[i].first,a[i].second);
	}
	
	cout<<sum+1;
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