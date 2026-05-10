#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<n ;i++)

void solve(){
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	rep(i,n) cin>>a[i];
	
	ll sum=0;
	rep(i,n) sum+=a[i];
	
	sort(a.begin(),a.end());
	a[n-1]--;
	sort(a.begin(),a.end());
	
	int mx=a[n-1];
	int mn=a[0];
	
	if(mx-mn>k||sum%2==0){
		cout<<"Jerry";
	}
	else cout<<"Tom";
}

signed main(){
	int t;
	cin>>t;
	while(t--){
		solve();
		cout<<"\n";
	}
}