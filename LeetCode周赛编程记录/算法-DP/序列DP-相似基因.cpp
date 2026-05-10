#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int INF = 1e9;

// 碱基相似度矩阵
int score[5][5] = {
    { 5, -1, -2, -1, -3},  // A
    {-1,  5, -3, -2, -4},  // C
    {-2, -3,  5, -2, -2},  // G
    {-1, -2, -2,  5, -1},  // T
    {-3, -4, -2, -1,  0}   // -
};

int id(char c){
    if(c == 'A') return 0;
    if(c == 'C') return 1;
    if(c == 'G') return 2;
    if(c == 'T') return 3;
    return 4; // '-'
}

// ACGT - > 1 2 3 4
int n1, n2, a[N], b[N];
string s1, s2;
int dp[N][N];

void solve(){
	cin >> n1 >> s1;
	cin >> n2 >> s2;
	
	// 初始化开头与空匹配
	for(int i = 1; i <= n1; i ++){
		dp[i][0] = dp[i - 1][0] + score[id(s1[i - 1])][4];
	}
	for(int j = 1; j <= n2; j ++){
		dp[0][j] = dp[0][j - 1] + score[4][id(s2[j - 1])];
	}
	
	for(int i = 1; i <= n1; i ++){
		for(int j = 1; j <= n2; j ++){
			dp[i][j] = max({
				dp[i - 1][j - 1] + score[id(s1[i - 1])][id(s2[j - 1])], // s1 与 s2匹配
				dp[i - 1][j] + score[id(s1[i - 1])][4], // s1 与 '-'匹配
				dp[i][j - 1] + score[4][id(s2[j - 1])] // s2 与 '-'匹配
			});
		}
	}
	
	cout << dp[n1][n2];
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
}
