#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,b) for(int i=a;i<=b;i++)

const int INF=1e4;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n+1);
	rep(i,1,n) cin>>a[i];
	
	vector<int> dp(n+1);//以i为结尾的最大和
	dp[0]=0;
	
	int ans=-INF;
	rep(i,1,n){
		dp[i]=max(a[i],a[i]+dp[i-1]);//最大值取决于是否连接到前一个数的后面
		ans=max(ans,dp[i]);
	}
	
	cout<<ans;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}