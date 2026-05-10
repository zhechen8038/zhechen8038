#include<bits/stdc++.h>
using namespace std;

void solve(){
    vector<int> h;
    int x;
    while(cin >> x) h.push_back(x);

    // 1. 最长不增子序列长度
    vector<int> dp(h.size(), 1);
    for(int i = 0; i < (int)h.size(); i++) {
        for(int j = 0; j < i; j++) {
            if(h[j] >= h[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int ans1 = *max_element(dp.begin(), dp.end());
    cout << ans1 << "\n";

    // 2. 最少系统数
    multiset<int> s;
    for(int v : h) {
        auto it = s.lower_bound(v); // 找到第一个 >= v 的链尾
        if(it == s.end()) {
            s.insert(v);
        } else {
            s.erase(it);
            s.insert(v);
        }
    }
    int ans2 = s.size();
    cout << ans2 << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
