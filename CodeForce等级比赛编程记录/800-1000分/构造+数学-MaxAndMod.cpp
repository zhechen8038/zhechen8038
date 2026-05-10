#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);i++)

void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	rep(i,n) a[i]=i+1;
	if(n%2==0){
		cout<<"-1";
	}
	else{
		cout<<n<<" ";
		rep(i,n-1) cout<<a[i]<<" ";
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