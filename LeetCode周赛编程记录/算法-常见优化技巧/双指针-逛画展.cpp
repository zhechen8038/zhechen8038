#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,b) for(int i=a;i<=b;i++)

void solve(){
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1);
	rep(i,1,n) cin>>a[i];
	
	unordered_map<int,int> cnt;
	
	int total=0;
	int l=1,ans_l=1,ans_r=n,min_len=n+1;
	
	rep(r,1,n){
		cnt[a[r]]++;
		if(cnt[a[r]]==1) total++;
		
		while(total==m){
			if(r-l+1<min_len){
				min_len=r-l+1;
				ans_l=l;ans_r=r;
			}
			
			//右移窗口左边
			cnt[a[l]]--;
			if(cnt[a[l]]==0) total--;
			l++;
		}
	}
	
	cout<<ans_l<<" "<<ans_r;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}