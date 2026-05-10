#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);i++)

void solve(){
	int n;
	cin>>n;
	vector<ll> a(n);
	rep(i,n) cin>>a[i];
	
	ll dif=a[1]-a[0];
	for(int i=2;i<n;i++){
		if(a[i]-a[i-1]!=dif){
			cout<<"NO";
			return;
		}
	}
	
	if(dif>0){
		rep(i,n) a[i]-=(i+1)*dif;
		rep(i,n){
			if(a[i]<0||a[i]%(n+1)!=0){
				cout<<"NO";
				return;
			}
		}
		cout<<"YES";
	}
	
	else{
		rep(i,n) a[i]+=(n-i)*dif;
		rep(i,n){
			if(a[i]<0||a[i]%(n+1)!=0){
				cout<<"NO";
				return;
			}
		}
		cout<<"YES";
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