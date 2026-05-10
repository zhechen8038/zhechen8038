#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);i++)

int gcd(int a,int b){
	return b==0 ? a:gcd(b,a%b);
}

void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	rep(i,n) cin>>a[i];
	int mn,mx;
	mn=*min_element(a.begin(),a.end());
	mx=*max_element(a.begin(),a.end());
	if(mn==mx){
		cout<<"NO";
		return;
	}
	cout<<"YES\n";
	rep(i,n){
		if(a[i]==mx) cout<<"2"<<" ";
		else cout<<"1"<<" ";
	}
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