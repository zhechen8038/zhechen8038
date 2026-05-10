#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<n ;i++)

void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	rep(i,n) cin>>a[i];
	
	ll ans=1e18;
	int i=0;
	while(i<n){
		int j=i;
		while(j<n&&a[j]==a[i]) j++;
		ll cost=1LL*(i+n-j)*a[i];
		ans=min(ans,cost);
		i=j;
	}
	cout<<ans;
}

signed main(){
	int t;
	cin>>t;
	while(t--){
		solve();
		cout<<"\n";
	}
}