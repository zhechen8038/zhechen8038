#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 5;
const int MOD = 998244353;

int n;
ll p;

ll fast_pow(int b){
	ll res = 1;
	ll a = p;
	while(b > 0)
	{
		if(b & 1) res=(res * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}

void solve(){
	cin >> n >> p;
	ll ans = 1;
	for(int i = 1; i <= n; i ++)
	{
		int ai;
		cin >> ai;
		ans = (ans * (1 + fast_pow(ai))) % MOD;
	}
		
	cout << ans;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}