#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);i++)

void solve(){
	int x,y,a;
	cin>>x>>y>>a;
	double dep=a+0.5;
	if(x>dep){
		cout<<"NO";
		return;
	}
	int count=ceil(dep/(x+y));
	if((x+y)*count-y>=dep) cout<<"NO";
	else cout<<"YES";
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