#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
	int n, k;
	cin >> n >> k;
	
	vector<int> a(n + 1);
	vector<pair<int,int>> vec;
	ll ans = 0;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	for(int i = 1; i <= n; i ++){
		int b;
		cin >> b;
		if(a[i] > b) swap(a[i], b);
		ans += b - a[i];
		vec.push_back({a[i], b});
	}
	
	sort(vec.begin(), vec.end()); // 按照a[i]的大小排序
	// 检查有无交叉区间，有交叉区间，这两个区间就不用动了
	// 没有交叉，找最小交叉的多出来的间隙，2倍间隙就是重排列多出来的值
	int mn = INT_MAX;
	for(int i = 1; i < n; i ++){
		if(vec[i - 1].second >= vec[i].first){
			cout << ans;
			return;
		}
		int dis = vec[i].first - vec[i - 1].second;
		mn = min(mn, dis);
	}
	
	ans += 2 * mn;
	cout << ans;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while(t --){
		solve();
		cout << "\n";
	}
}