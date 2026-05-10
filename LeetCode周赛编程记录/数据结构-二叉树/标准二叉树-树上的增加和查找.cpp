#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)

const int MAX = 1e6 + 5;  // 树的最大节点数
const int INF = 2147483647;  // 定义无穷大，用于前驱和后继的初始值

// 定义树的节点结构
struct node {
    int val;    // 节点存储的值
    int ls;     // 左子节点索引
    int rs;     // 右子节点索引
    int cnt;    // 当前节点值的出现次数
    int siz;    // 以当前节点为根的子树的大小（包括左右子树）
};

node tree[MAX];  // 静态分配树节点数组
int node_count = 0;  // 记录当前已使用的节点数

// 向树中插入一个值
void add(int x, int v) {
    tree[x].siz++;  // 当前子树大小增加

    // 如果值已存在，增加计数
    if (tree[x].val == v) {
        tree[x].cnt++;
        return;
    }

    // 插入右子树（当前节点值 < 插入值）
    if (tree[x].val < v) {
        if (tree[x].rs == 0) {  // 右子节点为空，创建新节点
            node_count++;
            tree[node_count].val = v;
            tree[node_count].cnt = tree[node_count].siz = 1;
            tree[x].rs = node_count;
        } else {
            add(tree[x].rs, v);  // 递归插入右子树
        }
    }
    // 插入左子树（当前节点值 > 插入值）
    else {
        if (tree[x].ls == 0) {  // 左子节点为空，创建新节点
            node_count++;
            tree[node_count].val = v;
            tree[node_count].cnt = tree[node_count].siz = 1;
            tree[x].ls = node_count;
        } else {
            add(tree[x].ls, v);  // 递归插入左子树
        }
    }
}

// 查询值 v 的前驱（最大的小于 v 的数）
int queryfr(int x, int v) {
    int ans = -INF;  // 初始化为最小值
    while (x != 0) {
        if (tree[x].val >= v) {
            x = tree[x].ls;  // 当前值 >= v，向左子树搜索
        } else {
            ans = tree[x].val;  // 当前值 < v，更新候选答案
            x = tree[x].rs;      // 继续向右子树搜索更大的候选
        }
    }
    return ans;
}

// 查询值 v 的后继（最小的大于 v 的数）
int queryne(int x, int v) {
    int ans = INF;  // 初始化为最大值
    while (x != 0) {
        if (tree[x].val <= v) {
            x = tree[x].rs;  // 当前值 <= v，向右子树搜索
        } else {
            ans = tree[x].val;  // 当前值 > v，更新候选答案
            x = tree[x].ls;     // 继续向左子树搜索更小的候选
        }
    }
    return ans;
}

// 查询值 v 的排名（比 v 小的数的个数 +1）
int queryval(int x, int v) {
    int ans = 0;
    while (x != 0) {
        if (v == tree[x].val) {
            ans += tree[tree[x].ls].siz;  // 左子树的大小即为比 v 小的数的个数
            break;
        } else if (v < tree[x].val) {
            x = tree[x].ls;  // 向左子树搜索
        } else {
            ans += tree[tree[x].ls].siz + tree[x].cnt;  // 累加左子树和当前节点的计数
            x = tree[x].rs;  // 向右子树搜索
        }
    }
    return ans + 1;  // 排名 = 比 v 小的数的个数 +1
}

// 查询排名为 rk 的值
int queryrk(int x, int rk) {
    while (x != 0) {
        if (tree[tree[x].ls].siz >= rk) {
            x = tree[x].ls;  // 左子树的大小 >= rk，向左子树搜索
        } else if (tree[tree[x].ls].siz + tree[x].cnt >= rk) {
            return tree[x].val;  // 当前节点的范围包含 rk
        } else {
            rk -= tree[tree[x].ls].siz + tree[x].cnt;  // 调整 rk，向右子树搜索
            x = tree[x].rs;
        }
    }
    return INF;  // 未找到（理论上不会执行）
}

void solve() {
    int n;
    cin >> n;  // 操作次数
    while (n--) {
        int op, x;
        cin >> op >> x;  // 操作类型和参数

        if (op == 1) {
            // 查询 x 的排名
            cout << queryval(1, x) << "\n";
        } else if (op == 2) {
            // 查询排名为 x 的值
            cout << queryrk(1, x) << "\n";
        } else if (op == 3) {
            // 查询 x 的前驱
            cout << queryfr(1, x) << "\n";
        } else if (op == 4) {
            // 查询 x 的后继
            cout << queryne(1, x) << "\n";
        } else if (op == 5) {
            // 插入 x
            if (node_count == 0) {  // 树为空，初始化根节点
                node_count++;
                tree[1].val = x;
                tree[1].cnt = tree[1].siz = 1;
            } else {
                add(1, x);  // 递归插入
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 初始化 tree[0]，避免未定义行为
    tree[0].val = 0;
    tree[0].ls = tree[0].rs = 0;
    tree[0].cnt = tree[0].siz = 0;

    solve();
    return 0;
}