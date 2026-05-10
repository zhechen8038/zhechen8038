#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;i++)

void solve(){
	int n,px,py,qx,qy;
	cin>>n>>px>>py>>qx>>qy;
	vector<double> a(n+1);
	rep(i,n) cin>>a[i];
	a[n]=sqrt(1.0*(px-qx)*(px-qx)+1.0*(py-qy)*(py-qy));
	sort(a.begin(),a.end());
	if(n==1){
		if(a[0]==a[1]){
			cout<<"Yes";
		}
		else cout<<"No";
	}
	else{
		double sum=a[n];
		for(int i=0;i<n;i++){
			sum-=a[i];
		}
		if(sum<=0){
			cout<<"Yes";
		}
		else{
			cout<<"No";
		}
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