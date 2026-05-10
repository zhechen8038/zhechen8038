#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;i++)

void solve(){
	int n;
	cin>>n;
	vector<int> cnt(1e5+1,0);
	queue<pair<int,int>> q;
	
	int ans=0;
	while(n--){
		int t,k;
		cin>>t>>k;
		
		for(int i=1;i<=k;i++){
			int x;
			cin>>x;
			q.push({t,x});
			cnt[x]++;
			if(cnt[x]==1) ans++;
		}
		
		pair<int,int> f=q.front();
		int nt=f.first,nx=f.second;
		
		while(nt>t||nt<=t-86400){
			cnt[nx]--;
			if(cnt[nx]==0) ans--;
			q.pop();
			
			f=q.front();
			nt=f.first,nx=f.second;
		}
		
		cout<<ans<<"\n";
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	solve();
}