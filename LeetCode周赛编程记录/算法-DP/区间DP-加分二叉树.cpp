#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 35;

int n, a[N];
int dp[N][N], root[N][N];

void preorder(int l, int r){
	if(l > r) return;
	int k = root[l][r];
	cout << k << " ";
	preorder(l, k - 1);
	preorder(k + 1, r);
}
void solve(){
	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	
	// 初始化叶子节点
	for(int i = 1; i <= n; i ++){
		dp[i][i] = a[i];
		root[i][i] = i; // 叶子节点的根是本身
	}
	
	// 区间DP
	for(int l = 2; l <= n; l ++){
		for(int i = 1; i + l - 1 <= n; i ++){
			int j = i + l - 1;
			// 遍历最优根k
			dp[i][j] = 0;
			for(int k = i; k <= j; k ++){
				int left = (k > i) ? dp[i][k - 1] : 1;
				int right = (k < j) ? dp[k + 1][j] : 1;
				int score = left * right + a[k];
				if(score > dp[i][j]){
					dp[i][j] = score;
					root[i][j] = k;
				}
			}
		}
	}
	
	cout << dp[1][n] << "\n";
	preorder(1, n);
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}