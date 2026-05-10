#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 105;
const int INF = 9999;

int n, m;
int a[N][N];

void solve(){
	cin >> n >> m;
	for(int i = 1; i <= m; i ++){
		for(int j = 1; j <= n; j ++){
			cin >> a[i][j];
		}
	}
	
	vector<int> dp(5000, INF); // 表示从初始状态到i状态需要的操作数
	dp[(1 << n) - 1] = 0;
	
	queue<int> q;
	q.push((1 << n) - 1);
	
	while(!q.empty()){
		int b = q.front(); q.pop();
		
		// 遍历每一个开关
		for(int i = 1; i <= m; i ++){
			
			int x = b;
			
			// 遍历每一个灯
			for(int j = 1; j <= n; j ++){
				if(a[i][j] == 0) continue;
				if(a[i][j] == 1) x &= (1 << n) - 1 - (1 << (j - 1));
				if(a[i][j] == -1) x |= (1 << (j - 1));
			}
			
			if(x == 0){
				cout << dp[b] + 1;
				return;
			}
			
			if(dp[b] + 1 < dp[x]){ // 缩小操作数
				dp[x] = dp[b] + 1;
				q.push(x); // 更新状态
			}
		}
	}
	
	cout << -1;
	
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}