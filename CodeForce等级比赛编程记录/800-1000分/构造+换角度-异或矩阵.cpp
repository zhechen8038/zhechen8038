#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);i++)

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> a(n,vector<int>(m));
	rep(i,n){
		string s;
		cin>>s;
		rep(j,m) a[i][j]=s[j]-'0';
	}
	int rcnt,lcnt;
	rcnt=0;lcnt=0;
	rep(i,n){
		int c=0;
		rep(j,m){
			c=c^a[i][j];
		}
		if(c==1) rcnt++;
	}
	rep(j,m){
		int c=0;
		rep(i,n){
			c=c^a[i][j];
		}
		if(c==1) lcnt++;
	}
	cout<<max(rcnt,lcnt);
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