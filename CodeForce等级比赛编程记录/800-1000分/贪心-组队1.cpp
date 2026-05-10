#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);i++)

void solve(){
	int n,x;
	cin>>n>>x;
	vector<int> a(n);
	rep(i,n) cin>>a[i];
	
	sort(a.rbegin(),a.rend());
	
	int ans=0;
	int count=0;
	rep(i,n){
		count++;
		if(a[i]*count>=x){
			ans++;
			count=0;
		}
	}
	cout<<ans;
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