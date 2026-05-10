//传纸条
#include<bits/stdc++.h>
using namespace std;
int main(){
	int m,n;
	cin>>m>>n;
	int a[m+1][n+1];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	
	int dp[m+n+1][m+1][n+1];
	memset(dp,0,sizeof(dp));
	
	dp[2][1][1]=a[1][1];
	
	for(int k=3;k<=m+n;k++){
		for(int i1=1;i1<=m;i1++){
			for(int i2=1;i2<=m;i2++){
				int j1=k-i1;
				int j2=k-i2;
				if(j1<1||j1>n||j2<1||j2>n) continue;
				if((i1==i2&&j1==j2)&&(i1!=1||j1!=1)&&(i1!=m||j1!=n)) continue;
				
				int res=0;
				if(i1>1&&i2>1) res=max(res,dp[k-1][i1-1][i2-1]);
				if(i1>1&&j2>1) res=max(res,dp[k-1][i1-1][i2]);
				if(j1>1&&i2>1) res=max(res,dp[k-1][i1][i2-1]);
				if(j1>1&&j2>1) res=max(res,dp[k-1][i1][i2]);
				
				dp[k][i1][i2]=res+a[i1][j1]+a[i2][j2];
			}
		}
	}
	
	cout<<dp[m+n][m][m];
	return 0;
}