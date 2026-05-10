#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);i++)


void solve(){
	int n,x;
	cin>>n>>x;
	
	if(n==1){
		cout<<"0";
		return;
	}
	
	vector<int> a(n);
	rep(i,n) a[i]=i;
	
	if(n==x){
		rep(i,n) cout<<a[i]<<" ";
		return;
	}
	
	a[n-1]=x;
	a[x]=n-1;
	rep(i,n) cout<<a[i]<<" ";
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