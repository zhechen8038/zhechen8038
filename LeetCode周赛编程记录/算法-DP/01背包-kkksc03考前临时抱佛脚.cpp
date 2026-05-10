#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;i++)

int min_t(const vector<int>& s){
	int sum=0;
	int n=s.size();
	
	rep(i,n) sum+=s[i];
	
	int target=sum/2;
	
	vector<bool> dp(target+1,false);//是否存在时间总和为i的子集合
	dp[0]=true;//存在空集
	
	for(int num:s){
		for(int j=target;j>=num;j--){
			if(dp[j-num]) dp[j]=true;
		}
	}
	
	//找最大的子集
	int mx=0;
	for(int i=target;i>=0;i--){
		if(dp[i]){
			mx=i;
			break;
		}
	}
	
	int ans=max(mx,sum-mx);
	
	return ans;
}

void solve(){
	int s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	vector<int> a(s1),b(s2),c(s3),d(s4);
	rep(i,s1) cin>>a[i];
	rep(i,s2) cin>>b[i];
	rep(i,s3) cin>>c[i];
	rep(i,s4) cin>>d[i];
	
	int ans=0;
	ans+=min_t(a);
	ans+=min_t(b);
	ans+=min_t(c);
	ans+=min_t(d);
	
	cout<<ans;
	
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int t=1;
	while(t--){
		solve();
		cout<<"\n";
	}
}