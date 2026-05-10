#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;i++)

void solve(){
	int n;
	cin>>n;
	
	vector<int> a(n);
	rep(i,n) cin>>a[i];
	
	vector<int> num(n+1,0);
	rep(i,n) num[a[i]]++;
	
	int p=0;
	for(int i=0;i<n+1;i++){
		if(num[i]<=0){
			p=i;
			break;
		}
	}
	
	
	//差分前缀和优化
	vector<int> dif(n+2,0);
	rep(i,p){
		int l,r;
		l=num[i];
		r=n-i-1;
		dif[l]++;
		dif[r+1]--;
	}
	
	vector<int> cnt(n+1);
	cnt[0]=dif[0];
	for(int k=1;k<=n;k++){
		cnt[k]=cnt[k-1]+dif[k];
	}
	
	rep(i,n+1) cout<<cnt[i]+1<<" ";
	
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