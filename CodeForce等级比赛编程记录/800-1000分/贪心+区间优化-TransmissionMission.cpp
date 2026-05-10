#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);i++)

void solve(){
	int n,m;
	cin>>n>>m;
	vector<ll> a(n);
	rep(i,n) cin>>a[i];
	
	if(m>=n){
		cout<<"0";
		return;
	}
	
	sort(a.begin(),a.end());
	
	vector<ll> gaps(n-1);
	for(int i=0;i<n-1;i++) gaps[i]=a[i+1]-a[i];
	sort(gaps.begin(),gaps.end(),greater<ll>());
	
	ll total=0;
	for(int i=0;i<m-1;i++) total+=gaps[i];
	
	ll ans=a[n-1]-a[0]-total;
	cout<<ans;
}



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}