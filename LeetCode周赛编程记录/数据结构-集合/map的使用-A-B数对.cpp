#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,b) for(int i=a;i<=b;i++)

map<int,int> cnt;

void solve(){
	int n,c;
	cin>>n>>c;
	
	vector<int> a(n);
	rep(i,0,n-1){
		cin>>a[i];
		cnt[a[i]]++;
	}
	
	ll ans=0;
	
	rep(i,0,n-1){
		int w=a[i]-c;
		if(cnt.count(w)){
			ans+=cnt[w];
		}
	}
	
	cout<<ans;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	solve();
}