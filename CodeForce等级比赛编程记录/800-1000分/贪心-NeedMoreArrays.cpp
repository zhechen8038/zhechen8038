#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

void solve(){
	int n;
	cin >> n;
	vector <int> a(n);
	rep (i,n) cin >> a[i];
	int last = -1;
	int ans = 0;
	rep (i,n) {
		if (a[i] > last + 1){
			ans++;
			last = a[i];
		}
	}
	cout << ans;
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