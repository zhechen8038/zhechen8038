#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(n);i++)

void solve(){
	int n,k;
	cin>>n>>k;
	vector<int> a(n,0);
	if(k==0){
		rep(i,n) cout<<"0";
		return;
	}
	if(k==n){
		rep(i,n) cout<<"1";
		return;
	}
	if(k==1){
		a[0]=1;
		rep(i,n) cout<<a[i];
		return;
	}
	if(k>=2){
		a[0]=1;
		a[n-2]=1;
		k-=2;
		for(int i=n-3;i>=0;i--){
			if(k==0) break;
			a[i]=1;
			k--;
		}
	}
	rep(i,n) cout<<a[i];
	
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	int t;
	cin>>t;
	
	while(t--){
		solve();
		cout<<"\n";
	}
	return 0;
}