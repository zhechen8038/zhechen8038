#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<n ;i++)

void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	rep(i,n) cin>>a[i];
	rep(i,n-1){
		if(abs(a[i+1]-a[i])<=1){
			cout<<"0";
			return;
		}
	}
	for(int i=1;i<n-1;i++){
		if(a[i]>a[i-1]&&a[i]>a[i+1]){
			cout<<"1";
			return;
		}
		if(a[i]<a[i-1]&&a[i]<a[i+1]){
			cout<<"1";
			return;
		}
	}
	cout<<"-1";
}

signed main(){
	int t;
	cin>>t;
	while(t--){
		solve();
		cout<<"\n";
	}
}