#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void solve() {
    string s;
    int target;
    cin >> s >> target;
    int n = s.size();

    vector<vector<int>> dp(n + 1, vector<int>(target + 1, INF));
    dp[n][0] = 0; // 末尾已经凑出目标，0个加号

    for (int pos = n - 1; pos >= 0; pos--) {
        for (int sum = 0; sum <= target; sum++) {
            long long num = 0;
            for (int i = pos; i < n; i++) {
                num = num * 10 + (s[i] - '0');
                if (num > sum) break; // 剪枝：超过剩余目标
                if (dp[i + 1][sum - num] != INF) {
                    if (i + 1 == n)
                        dp[pos][sum] = min(dp[pos][sum], dp[i + 1][sum - num]);
                    else
                        dp[pos][sum] = min(dp[pos][sum], dp[i + 1][sum - num] + 1);
                }
            }
        }
    }

    if (dp[0][target] == INF)
        cout << -1 << "\n";
    else
        cout << dp[0][target] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
