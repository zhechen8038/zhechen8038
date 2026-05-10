#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> putInf;
vector<int> used;
vector<vector<int>> ans;

bool judge(int curRow, int col) {
    for (int i = 0; i < curRow; i++) {
        if (abs(curRow - i) == abs(col - putInf[i])) {
            return false;
        }
    }
    return true;
}

void queens(int curRow) {
    if (curRow == N) {
        ans.push_back(putInf);
        return;
    }
    for (int col = 0; col < N; col++) {
        if (used[col]) continue;
        if (judge(curRow, col)) {
            used[col] = true;
            putInf.push_back(col);
            queens(curRow + 1);
            putInf.pop_back();
            used[col] = false;
        }
    }
}

int main() {
    cin >> N;
    used.resize(N, false);
    queens(0);
    int count = 0;
    for (const auto &solution : ans) {
        if (count >= 3) break;
        for (int col : solution) {
            cout << col + 1 << " ";
        }
        cout << endl;
        count++;
    }
    cout << ans.size() << endl;
    return 0;
}