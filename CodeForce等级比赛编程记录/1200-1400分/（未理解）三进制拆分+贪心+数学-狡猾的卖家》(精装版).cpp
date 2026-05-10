#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector <ll> cost;
void init(){
	ll c = 3; // cost[0] = 3
	ll cnt = 1; // 3^0
	for(int i = 0; i <= 21; i ++){
		cost.push_back(c);
		c = 3 * c + cnt;
		cnt *= 3;
	}
}

void solve(){
	int n, k;
	cin >> n >> k;
	
	vector<int> tr;
	ll min_k = 0;
	while(n){ // 三进制拆分
		min_k += (n % 3); // 该进制位要计算几次，如果可以被3整除，则跳动上一位
		tr.push_back(n % 3);
		n /= 3; // 进制向右移
	}
	
	if(min_k > k){
		cout << -1;
		return;
	}
	
	// 初始方案需要 min_k 次交易
	// 每一次“三合一”操作可以 减少 2 次交易
	// 所以我们最多能做 k/2 次合并。
	k -= min_k;
	k /= 2;
	
	for(int i = (int)tr.size() - 1; i >= 1; i --){
		if(tr[i] <= k){
			tr[i - 1] += 3 * tr[i];
			k -= tr[i];
			tr[i] = 0;
		}
		else{
			tr[i - 1] += 3 * k;
			tr[i] -= k;
			k = 0;
			break;
		}
	}
	
	ll ans = 0;
	for(int i = 0; i < (int)tr.size(); i ++){
		ans += tr[i] * cost[i];
	}
	
	cout << ans;
	
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	init();
	while(t--){
		solve();
		cout << "\n";
	}
}