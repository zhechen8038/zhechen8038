#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);i++)

void solve(){
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	
	int cnt=0;
	rep(i,n){
		if(s[i]=='1') cnt++;
	}
	
	if(cnt<=k||n<2*k){
		cout<<"Alice";
	}
	else{
		cout<<"Bob";
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