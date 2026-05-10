#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<n ;i++)

void solve(){
	int n,m,a,b;
	cin>>n>>m>>a>>b;
	
	vector<pair<int,int>> rec={{a,m},{n-a+1,m},{n,b},{n,m-b+1}};
	
	int ans=n+m;
	for(auto &p:rec){
		int n1=p.first;
		int m1=p.second;
		
		int res=0;
		while(n1>1){
			n1=(n1+1)/2;
			res++;
		}
		while(m1>1){
			m1=(m1+1)/2;
			res++;
		}
		ans=min(ans,res);
	}
	
	cout<<1+ans;
}

signed main(){
	int t;
	cin>>t;
	while(t--){
		solve();
		cout<<"\n";
	}
}