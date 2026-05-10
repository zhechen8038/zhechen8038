#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);i++)

void solve(){
	int n;
	cin>>n;
	if(n%2==0){
		cout<<"-1";
	}
	else{
		for(int i=1;i<=n;i+=2) cout<<i<<" ";
		for(int i=2;i<=n;i+=2) cout<<i<<" ";
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