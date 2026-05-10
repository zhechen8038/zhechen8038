#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;i++)

void solve(){
	ll n,l,r,k;
	cin>>n>>l>>r>>k;
	if(n%2!=0){
		cout<<l;
		return;
	}
	if(n==2){
		cout<<-1;
		return;
	}
	
	ll best=-1;
	for(ll i=1;i<=r;i*=2){
		if(i>=l&&(i&l)==0){
			best=i;
			break;
		}
	}
	
	if(best==-1){
		cout<<best;
	}
	else{
		if(k<n-1){
			cout<<l;
		}
		else{
			cout<<best;
		}
	}
	
	
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