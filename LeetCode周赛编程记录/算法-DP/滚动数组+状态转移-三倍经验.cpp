#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 105;
const ll NEG = -4e18; // 负无穷，表示不可达

int n, k;
ll a[N][N];
ll dp[N][20005], pre[N][20005]; // 滚动数组 + 状态转移

void solve(){
    cin >> n >> k;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= i; j ++){
            cin >> a[i][j];
        }
    }
    
    // 初始化第一行
    for(int x = 0; x <= k; x ++) pre[1][x] = NEG;
    pre[1][0] = a[1][1];
    if(k > 0) pre[1][1] = 3 * a[1][1];
    
    for(int i = 2; i <= n; i ++){
    	for(int j = 1; j <= i; j ++){
    		for(int x = 0; x <= k; x ++){
    			dp[j][x] = NEG;
    			
    			// 从左上来
    			if(j > 1){
    				dp[j][x] = max(dp[j][x], pre[j - 1][x] + a[i][j]);
    				if(x > 0){
    					dp[j][x] = max(dp[j][x], pre[j - 1][x - 1] + 3 * a[i][j]);
    				}
    			}
    			
    			// 从右上来
    			if(j <= i - 1){
    				dp[j][x] = max(dp[j][x], pre[j][x] + a[i][j]);
    				if(x > 0){
    					dp[j][x] = max(dp[j][x], pre[j][x - 1] + 3 * a[i][j]);
    				}
    			}
    		}
    	}
    	
    	swap(dp, pre);
    }
    
    ll ans = NEG;
    for(int j = 1; j <= n; j ++){
    	for(int x = 0; x <= k; x ++){
    		ans = max(ans, pre[j][x]);
    	}
    }
    
    cout << ans;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
}
