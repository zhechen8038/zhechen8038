#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=1;i<=n;i++)

void solve(){
	int n;
	cin>>n;
	double x[n+1],y[n+1];
	double dp[n+1][34000];
	double dis[n+1][n+1];
	
	rep(i,n) cin>>x[i]>>y[i];
	memset(dp,127,sizeof(dp));
	
	x[0]=0,y[0]=0;
	double ans=dp[0][0];
	
	for(int i=0;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			dis[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
			dis[j][i]=dis[i][j];
		}
	}
	
	for(int i=1;i<=n;i++){
		dp[i][(1<<(i-1))]=dis[0][i];
	}
	
	for(int k=1;k<(1<<n);k++){
		for(int i=1;i<=n;i++){
			if((k&(1<<(i-1)))==0) continue;
			
			for(int j=1;j<=n;j++){//访问i的前置节点
				if(i==j) continue;
				if((k&(1<<(j-1)))==0) continue;//j是已被访问的
				
				dp[i][k]=min(dp[i][k],dp[j][k-(1<<(i-1))]+dis[j][i]);//k-(1<<(i-1))表示未访问i的状态
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		ans=min(ans,dp[i][(1<<n)-1]);
	}
	
	cout << fixed << setprecision(2) << ans;
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