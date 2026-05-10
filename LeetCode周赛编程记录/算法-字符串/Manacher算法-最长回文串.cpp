#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
	string s;
	cin >> s;
	int n = s.size();
	
	int ans = 0;
	
	vector<int> d1(n);
	for(int i = 0, l = 0, r = -1; i < n; i ++){
		int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
		while(i - k >= 0 && i + k < n && s[i - k] == s[i + k]){
			k ++;
		}
		d1[i] = k --;
		if(i + k > r){
			l = i - k;
			r = i + k;
		}
		ans = max(ans, 2 * d1[i] - 1);
	}
	
	vector<int> d2(n);
	for(int i = 0, l = 0, r = -1; i < n; i ++){
		int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
		while(i - k - 1>= 0 && i + k < n && s[i - k - 1] == s[i + k]){
			k ++;
		}
		d2[i] = k --;
		if(i + k > r){
			l = i - k - 1;
			r = i + k;
		}
		ans = max(ans, 2 * d2[i]);
	}
	
	cout << ans;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}