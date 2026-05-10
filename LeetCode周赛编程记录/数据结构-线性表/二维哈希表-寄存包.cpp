#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;i++)

void solve(){
	int n,q;
	cin>>n>>q;
	unordered_map<int,unordered_map<int,int>> a;
	
	while(q--){
		int x,i,j;
		cin>>x>>i>>j;
		if(x==1){
			int k;
			cin>>k;
			a[i][j]=k;
		}
		else{
			cout<<a[i][j]<<"\n";
		}
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	solve();
}