#include <bits/stdc++.h>
using namespace std;

const int N = 40005;
int dp[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, W;
    cin >> n >> W;

    for (int i = 0; i < n; i++) {
        int v, w, m;              // v=价值, w=重量, m=件数上限
        cin >> v >> w >> m;

        // 关键：拍一份“旧的 dp”，本轮所有读取都从 prev 读
        static int prev[N];
        memcpy(prev, dp, (W + 1) * sizeof(int));

        // 按重量余数分组
        for (int r = 0; r < w; r++) {
            deque<int> q;         // 存组内下标 t（容量 idx = r + t*w）
            // 组内从小到大扫
            for (int t = 0, idx = r; idx <= W; t++, idx += w) {

                // 1) 移出超过件数窗口的起点
                while (!q.empty() && t - q.front() > m) q.pop_front();

                // 2) 先把“不选该物品”的情况写入（k=0），保证下界
                dp[idx] = prev[idx];

                // 3) 用窗口中最优起点更新（选 1..m 件）
                if (!q.empty()) {
                    int j = q.front();
                    dp[idx] = max(dp[idx], prev[r + j * w] + (t - j) * v);
                }

                // 4) 维护单调性（基于 prev，而不是已经更新过的 dp）
                //    维护的是 prev[r + t'*w] - t'*v 的最大值
                auto value_at = [&](int T) {
                    return prev[r + T * w] - T * v;
                };
                while (!q.empty() && value_at(q.back()) <= value_at(t))
                    q.pop_back();

                // 5) 当前 t 入队，供后续更大的 t 使用
                q.push_back(t);
            }
        }
    }

    cout << dp[W] << '\n';
    return 0;
}
