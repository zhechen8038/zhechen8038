#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);i++)

void solve(){
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	rep(i,n) cin>>a[i];
	int cur=a[k-1];
	sort(a.begin(),a.end());
	
	int w=1;
	rep(i,n){
		if(a[i]<=cur) continue;
		int t=a[i]-cur;
		if(w+t-1>cur){
			cout<<"NO";
			return;
		}
		cur=a[i];
		w+=t;
	}
	cout<<"YES";
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