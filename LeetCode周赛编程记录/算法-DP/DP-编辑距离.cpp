#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e8;

string a, b;

void solve(){
	cin >> a >> b;
	int n1 = a.size(), n2 = b.size();
	vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, INF));
	
	dp[0][0] = 0;
	for(int i = 1; i <= n1; i ++) dp[i][0] = i;
	for(int i = 1; i <= n2; i ++) dp[0][i] = i;
	
	for(int i = 1; i <= n1; i ++){
		for(int j = 1; j <= n2; j ++){
			if(a[i - 1] == b[j - 1]){
				dp[i][j] = dp[i - 1][j - 1];
			}
			else{
				dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1); // 删除ai
				dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1); // 插入bi
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1); // 将ai替换成bi
			}
		}
	}
	
	cout << dp[n1][n2];
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}