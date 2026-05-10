#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=1;i<=n;i++)

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> a(n+1,vector<int>(m+1));
	vector<vector<int>> b(n+1,vector<int>(m+1,0));
	
	rep(i,n){
		rep(j,m){
			cin>>a[i][j];
			b[i][j]=b[i-1][j]+b[i][j-1]+a[i][j]-b[i-1][j-1];
		}
	}
	
	int ans=0;
	int l=1;
	
	while(l<=min(n,m)){
		for(int i=l;i<=n;i++){
			for(int j=l;j<=m;j++){
				if(b[i][j]-b[i-l][j]-b[i][j-l]+b[i-l][j-l]==l*l){
					ans=max(ans,l);
				}
			}
		}
		l++;
	}
	
	cout<<ans;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	solve();
}