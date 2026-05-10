#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
	int n;
	cin >> n;
	int mn = INT_MAX;
	
	for(int i = 1; i <= n; i ++){
		int x;
		cin >> x;
		if(x <= mn) mn = x;
		else{
			if(x >= 2 * mn){
				cout << "NO\n";
				for(int j = i + 1; j <= n; j ++){
					cin >> x;
				}
				
				return;
			}
		}
	}
	
	cout << "YES\n";
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while(t --){
		solve();
	}
}