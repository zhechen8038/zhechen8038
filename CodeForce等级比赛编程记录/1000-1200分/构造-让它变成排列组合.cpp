#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);i++)

void solve(){
	int n;
	cin>>n;
	cout<<2*n-3<<"\n";
	for(int i=1;i<=n;i++){
		if(i==1&&i+1<n){
			cout<<i<<" "<<i+1<<" "<<n;
			cout<<"\n";
		}
		else if(i>1&&i+1<n){
			cout<<i<<" "<<1<<" "<<i;
			cout<<"\n";
			cout<<i<<" "<<i+1<<" "<<n;
			cout<<"\n";
		}
		else if(i>1&&i+1>=n){
			cout<<i<<" "<<1<<" "<<i;
			cout<<"\n";
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
	}
}