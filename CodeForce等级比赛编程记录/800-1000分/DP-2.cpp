#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n+1][n+1];
    memset(a, 0, sizeof(a));
    while(1){
        int t1,t2,t3;
        cin >> t1 >> t2 >> t3;
        if(t1==0 && t2==0 && t3==0) break;
        a[t1][t2] = t3;
    }
    
    int dp[2*n+1][n+1][n+1];
    memset(dp, 0, sizeof(dp));
    
    dp[2][1][1] = a[1][1];
    
    for(int k=3; k<=2*n; k++){
        for(int i1=1; i1<=n; i1++){
            for(int i2=1; i2<=n; i2++){
                int j1 = k - i1;
                int j2 = k - i2;
                if(j1 < 1 || j1 > n || j2 < 1 || j2 > n) continue;
                
                int res = 0;
                if(i1 > 1 && i2 > 1) res = max(res, dp[k-1][i1-1][i2-1]);
                if(i1 > 1 && j2 > 1) res = max(res, dp[k-1][i1-1][i2]);
                if(j1 > 1 && i2 > 1) res = max(res, dp[k-1][i1][i2-1]);
                if(j1 > 1 && j2 > 1) res = max(res, dp[k-1][i1][i2]);
                
                if(i1 == i2 && j1 == j2){
                    dp[k][i1][i2] = res + a[i1][j1];
                } else {
                    dp[k][i1][i2] = res + a[i1][j1] + a[i2][j2];
                }
            }
        }
    }
    
    cout << dp[2*n][n][n] << endl;
    return 0;
}