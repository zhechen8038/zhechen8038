#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;

int n;
int a[N], b[N];
int dp[N];

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i ++){
    	cin >> a[i];
    }
    for(int i = 1; i <= n; i ++){
    	cin >> b[i];
    }
    
    for(int i = 1; i <= n; i ++){
    	int prev = 0; // dp[i - 1][j - 1]
    	for(int j = 1; j <= n; j ++){
    		int temp = dp[j]; // dp[i - 1][j]
    		if(a[i] == b[j]){
    			dp[j] = prev + 1;
    		}
    		else{
    			dp[j] = max(dp[j], dp[j - 1]);
    		}
    		prev = temp;
    	}
    }
    
    cout << dp[n];
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
}
