#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);i++)


void solve(){
	int n;
	cin>>n;
	int ans;
	int max;
	if(n%2==0) max=n*(n/2);
	else max=(n+1)*(n/2);
	ans=max/2+1;
	cout<<ans;
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