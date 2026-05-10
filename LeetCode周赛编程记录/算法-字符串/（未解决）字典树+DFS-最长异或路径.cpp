#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;

struct trie {
    int nxt[N * 32][2], cnt = 1; // 多开空间
    void insert(int x){
        int p = 0;
        for(int i = 30; i >= 0; i--){
            int b = (x >> i) & 1;
            if(!nxt[p][b]) nxt[p][b] = cnt++;
            p = nxt[p][b];
        }
    }
    int query(int x){
        int p = 0, res = 0;
        for(int i = 30; i >= 0; i--){
            int b = (x >> i) & 1;
            if(nxt[p][b ^ 1]){ // 想走相反位
                res |= (1 << i);
                p = nxt[p][b ^ 1];
            } else {
                p = nxt[p][b];
            }
        }
        return res;
    }
};


int n;
vector<pair<int, int>> f[N];
int dis[N];
int vis[N];
trie t;

void dfs(int u, int fa){
    for(auto &p : f[u]){
    	int v = p.first, w = p.second;
        if(v == fa) continue;
        dis[v] = dis[u] ^ w; // 根到 v 的 xor 距离
        dfs(v, u);
    }
}

void solve(){
	cin >> n;
	for(int i = 0; i < n - 1; i ++){
		int u, v, w;
		cin >> u >> v >> w;
		f[u].push_back({v, w});
        f[v].push_back({u, w});
	}
	
	// step1: dfs求dis数组
    dfs(1, 0);

    // step2: 字典树求最大异或对
    int ans = 0;
    t.insert(dis[1]);
    for(int i = 2; i <= n; i++){
        ans = max(ans, t.query(dis[i]));
        t.insert(dis[i]);
    }

    cout << ans << "\n";
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}