#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(n);i++)

void solve(){
	int n,s;
	cin>>n>>s;
	int ans=0;
	rep(i,n){
		int dx,dy,x,y;
		cin>>dx>>dy>>x>>y;
		if((x==y&&dx*dy==1)||(x+y==s&&dx*dy==-1)) ans++;
	}
	cout<<ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	int t;
	cin>>t;
	
	while(t--){
		solve();
		cout<<"\n";
	}
	return 0;
}