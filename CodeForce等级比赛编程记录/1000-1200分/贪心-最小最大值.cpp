#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);i++)

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> a(n,vector<int>(m));
	rep(i,n) rep(j,m) cin>>a[i][j];
	
	int mx=0;
	rep(i,n) rep(j,m) if(mx<a[i][j]) mx=a[i][j];
	
	vector<int> rcnt(n,0),lcnt(m,0);
	int cnt=0;
	rep(i,n){
		rep(j,m){
			if(a[i][j]==mx){
				rcnt[i]++;
				lcnt[j]++;
				cnt++;
			}
		}
	}
	rep(i,n){
		rep(j,m){
			if(a[i][j]==mx&&rcnt[i]+lcnt[j]-1==cnt){
				cout<<mx-1;
				return;
			}
			if(a[i][j]!=mx&&rcnt[i]+lcnt[j]==cnt){
				cout<<mx-1;
				return;
			}
		}
	}
	cout<<mx;
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