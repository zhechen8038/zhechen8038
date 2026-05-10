#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=1;i<=n;i++)

const int MAX=32005;

int n,m;
int a[61],b[61],c[61];
int dp[MAX];
vector<int> f[61];

void solve(){
	cin>>m>>n;
	rep(i,n){
		cin>>a[i]>>b[i]>>c[i];
		b[i]*=a[i];
		if(c[i]){
			f[c[i]].push_back(i);
		}
	}
	
	rep(i,n){
		if(c[i]!=0) continue;
		vector<pair<int,int>> item;
		item.push_back({a[i],b[i]});
		
		if(f[i].size()>=1){
			int t=f[i][0];
			item.push_back({a[i]+a[t],b[i]+b[t]});
		} 
		if(f[i].size()>=2){
			int t=f[i][1];
			item.push_back({a[i]+a[t],b[i]+b[t]});
			item.push_back({a[i]+a[f[i][0]]+a[t],b[i]+b[f[i][0]]+b[t]});
		}
		
		for(int j=m;j>=0;j--){
			for(pair<int,int>& it:item){
				int p=it.first,q=it.second;
				
				if(p<=j){
					dp[j]=max(dp[j],dp[j-p]+q);
				}
			}
		}
	}
	
	cout<<dp[m];
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}