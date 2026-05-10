#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;

struct Eage{
	int u, v, w;
};

int n, m, s, t;
int fa[N];
Eage g[N];

int findz(int x){
	if(x == fa[x]) return x;
	return fa[x] = findz(fa[x]);
}

void merge(int x, int y){
	int fx = findz(x), fy = findz(y);
	fa[fx] = fy;
}

bool cmp(const Eage &a, const Eage &b){
	return a.w < b.w;
}

void k_func() {
    for (int i = 1; i <= m; i++) {
        int x = g[i].u, y = g[i].v, z = g[i].w;
        if (findz(x) != findz(y)) {
            merge(x, y);
            if (findz(s) == findz(t)) {
                cout << z << "\n"; // 直接输出当前边权
                return;
            }
        }
    }
    cout << -1 << "\n"; // 不连通
}

void solve(){
	cin >> n >> m >> s >> t;
	
	for(int i = 1; i <= n; i ++){
		fa[i] = i;
	}
	
	for(int i = 1; i <= m; i ++){
		int x, y, z;
		cin >> x >> y >> z;
		g[i].u = x;
		g[i].v = y;
		g[i].w = z;
	}
	
	sort(g + 1, g + m + 1, cmp);
	
	k_func();
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}