#include <bits/stdc++.h>
using namespace std;

const int N = 305;
const int INF = 1e9;

int n, a[N], pre[N];
int dp[N][N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
        dp[i][i] = 0;
    }

    for(int len = 2; len <= n; len++){
        for(int i = 1; i + len - 1 <= n; i++){
            int j = i + len - 1;
            dp[i][j] = INF;
            for(int k = i; k < j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + pre[j] - pre[i-1]);
            }
        }
    }

    cout << dp[1][n];
}
