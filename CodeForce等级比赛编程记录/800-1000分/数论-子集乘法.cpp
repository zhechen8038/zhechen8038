#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;i++)

ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}

ll lcm(ll a,ll b){
	return a/gcd(a,b)*b;
}

void solve(){
	int n;
	cin>>n;
	
	vector<ll> b(n);
	rep(i,n) cin>>b[i];
	
	ll x=1;
	rep(i,n-1){
		ll g=gcd(b[i],b[i+1]);
		ll val=b[i]/g;
		x=lcm(x,val);
	}
	cout<<x;
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