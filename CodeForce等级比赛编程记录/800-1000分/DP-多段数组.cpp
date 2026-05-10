#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int MAX = 1e6 + 5; // a[i] 最大范围，假设 <= 1e5

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i,n) cin >> a[i];

	vector<int> dp(n, 0);
	int res = 0;

	// 注意：我们需要维护“前面所有 a[j] <= a[i]-2 的最大 dp”
	// 用 map 来做动态维护（不会超时）
	map<int, int> val_to_dp;

	rep(i, n){
		// 找到 a[j] <= a[i]-2 中最大的 dp[j]
		auto it = val_to_dp.upper_bound(a[i] - 2);
		int best = 0;
		if(it != val_to_dp.begin()){
			--it;
			best = it->second;
		}
		dp[i] = best + 1;
		// 更新当前 a[i] 对应的最大 dp 值
		val_to_dp[a[i]] = max(val_to_dp[a[i]], dp[i]);
		res = max(res, dp[i]);
	}

	cout << res;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
		cout << "\n";
	}
	return 0;
}
