#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);i++)

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> a(n,vector<int>(m));
	vector<int> rcnt(n,0),lcnt(m,0);
	
	rep(i,n){
		string s;
		cin>>s;
		rep(j,m) a[i][j]=s[j]-'0';
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]){
				if(i>0&&j>0&&rcnt[i]<j&&lcnt[j]<i){
					cout<<"NO";
					return;
				}
				rcnt[i]++;
				lcnt[j]++;
			}
		}
	}
	cout<<"YES";
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