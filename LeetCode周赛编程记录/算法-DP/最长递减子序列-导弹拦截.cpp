#include <bits/stdc++.h>
using namespace std;

// LNIS：最长不增子序列
int LNIS(vector<int>& h) {
    vector<int> tails;
    for (int v : h) {
        int x = -v; // 转成不降
        auto it = upper_bound(tails.begin(), tails.end(), x); 
        if (it == tails.end()) tails.push_back(x);
        else *it = x;
    }
    return (int)tails.size();
}

// 最少系统数
int minSystems(vector<int>& h) {
    multiset<int> s;
    for (int v : h) {
        auto it = s.lower_bound(v);
        if (it == s.end()) s.insert(v);
        else {
            s.erase(it);
            s.insert(v);
        }
    }
    return (int)s.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> h;
    int x;
    while (cin >> x) h.push_back(x);

    cout << LNIS(h) << "\n";
    cout << minSystems(h) << "\n";
}
