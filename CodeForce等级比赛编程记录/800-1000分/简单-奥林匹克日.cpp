#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);i++)

void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	rep(i,n) cin>>a[i];
	int cnt2,cnt0,cnt3,cnt1,cnt5;
	cnt0=3;cnt1=1;cnt2=2;cnt3=1;cnt5=1;
	int ans=0;
	rep(i,n){
		if(a[i]==0) cnt0--;
		if(a[i]==1) cnt1--;
		if(a[i]==2) cnt2--;
		if(a[i]==3) cnt3--;
		if(a[i]==5) cnt5--;
		if(cnt0<=0&&cnt1<=0&&cnt2<=0&&cnt3<=0&&cnt5<=0){
			ans=i+1;
			break;
		}
	}
	cout<<ans;
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