#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct Mole{
	int t, x, y;
};

void solve(){
	int n, m;
	cin >> n >> m;
	vector<Mole> a(m);
	for(int i = 0; i < m; i ++){
		cin >> a[i].t >> a[i].x >> a[i].y;
	}
	
	vector<int> dp(m, 1);
	 int ans = 1, best = 0;
	 
	 for(int i = 0; i < m; i ++){
	 	// 只看 2000 个时间范围内的鼹鼠
	 	for(int j = i - 1; j >= 0 && a[i].t - a[j].t <= 2*n; j --){
	 		int dis = abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y);
	 		if(a[i].t - a[j].t >= dis){
	 			dp[i] = max(dp[i], dp[j] + 1);
	 		}
	 	}
	 	
	 	// 如果时间差更大，就可以从全局最优接过来
        if (i > 0 && a[i].t - a[i - 1].t > 2 * n) {
            dp[i] = max(dp[i], best + 1);
        }
	 	
	 	best = max(best, dp[i]); //更新全局最优值
	 	ans = max(ans, dp[i]);
	 }
	 
	 cout << ans;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}