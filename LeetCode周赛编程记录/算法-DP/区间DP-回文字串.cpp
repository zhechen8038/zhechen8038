#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1005;

string s;
int dp[N][N];

void solve(){
	cin >> s;
	int n = s.size();
	
	for(int i = 1; i <= n; i ++) dp[i][i] = 1;
	for(int l = 2; l <= n; l ++){
		for(int i = 1; i + l - 1 <= n; i ++){
			int j = i + l - 1;
			if(s[i - 1] == s[j - 1]){
				if(i + 1 == j) dp[i][j] = 2; // 相邻
				else dp[i][j] = dp[i + 1][j - 1] + 2;
			}
			else{
				dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
			}
		}
	}
	
	int ans = n - dp[1][n];
	
	cout << ans;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}