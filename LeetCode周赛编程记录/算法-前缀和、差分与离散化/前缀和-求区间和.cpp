#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,b) for(int i = a; i <= b; i++)

void solve(){
	int n,m;
	cin>>n;
	vector<int> a(n+1);
	vector<int> b(n+1);
	b[0]=0;
	
	rep(i,1,n){
		cin>>a[i];
		b[i]=b[i-1]+a[i];
	}
	
	cin>>m;
	while(m--){
		int l,r;
		cin>>l>>r;
		int ans=b[r]-b[l]+a[l];
		cout<<ans<<"\n";
	}
	
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}