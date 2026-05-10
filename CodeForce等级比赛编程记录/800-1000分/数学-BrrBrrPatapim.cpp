#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);i++)


void solve(){
	int n;
	cin>>n;
	vector<vector<int>> f(n,vector<int>(n));
	vector<int> visited(2*n+1,0);
	vector<int> a(2*n);
	rep(i,n){
		rep(j,n) cin>>f[i][j];
	}
	int k=1;
	for(int j=0;j<n;j++){
		a[k++]=f[0][j];
		visited[f[0][j]]=1;
	}
	for(int i=1;i<n;i++){
		a[k++]=f[i][n-1];
		visited[f[i][n-1]]=1;
	}
	for(int i=1;i<2*n+1;i++){
		if(!visited[i]){
			a[0]=i;
			break;
		}
	}
	rep(i,2*n) cout<<a[i]<<" ";
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