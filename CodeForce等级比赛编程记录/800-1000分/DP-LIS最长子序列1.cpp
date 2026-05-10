//子串距离
#include<bits/stdc++.h>
using namespace std;
string a,b;
int k;
int dp[2005][2005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>a>>b;
	cin>>k;
	
	a=' '+a,b=' '+b;
	
	int m=a.size();
	int n=b.size();
	for(int i=1;i<=m;i++) dp[i][0]=i*k; //a为空串
	for(int j=1;j<=n;j++) dp[0][j]=j*k; //b为空串
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			int cost=abs(a[i]-b[j]);
			dp[i][j]=min({dp[i-1][j-1]+cost,dp[i-1][j]+k,dp[i][j-1]+k});
		}
	}
	cout<<dp[m][n];
	return 0;
	
}