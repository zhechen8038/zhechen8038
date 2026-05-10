#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<n ;i++)

const int f[11]={0,1,2,3,5,8,13,21,34,55,89};

void solve(){
	int n,m;
	cin>>n>>m;
	while(m--){
		int w,l,h;
		cin>>w>>l>>h;
		int mn=min(w,l);
		mn=min(mn,h);
		if(mn<f[n]){
			cout<<"0";
			continue;
		}
		if(w>=f[n]+f[n-1]||l>=f[n]+f[n-1]||h>=f[n]+f[n-1]){
			cout<<"1";
		}
		else cout<<"0";
	}
}

signed main(){
	int t;
	cin>>t;
	while(t--){
		solve();
		cout<<"\n";
	}
}