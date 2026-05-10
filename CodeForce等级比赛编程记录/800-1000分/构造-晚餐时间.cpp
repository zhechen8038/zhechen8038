#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);i++)


void solve(){
	int n,m,p,q;
	cin>>n>>m>>p>>q;
	if(n%p==0){
		if(n/p*q==m) cout<<"YES";
		else cout<<"NO";
	}
	else cout<<"YES";
	
}



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int t;
	cin>>t;
	while(t--){
		solve();
		cout<<"\n";
	}
	return 0;
}