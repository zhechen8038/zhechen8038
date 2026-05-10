#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5;

struct Eage{
	int u, v, w;
};

int n, l;
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
	int tot = 0;
	int ans = 0;
    for (int i = 1; i <= l; i++) {
        int x = g[i].u, y = g[i].v, z = g[i].w;
        if (findz(x) != findz(y)) {
            merge(x, y);
            tot ++;
            ans += z;
        }
    }
    
    if(tot >= n - 1){
    	cout << ans;
    }
    else cout << -1;
}

void solve(){
	cin >> n;
	
	for(int i = 0; i <= n; i ++){
		fa[i] = i;
	}
	
	
	for(int i = 1; i <= n; i ++){
		l ++;
		int x;
		cin >> x;
		g[l].u = 0;
		g[l].v = i;
		g[l].w = x;
	}
	
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n; j ++){
			l ++;
			int x;
			cin >> x;
			g[l].u = i;
			g[l].v = j;
			g[l].w = x;
		}
	}
	
	sort(g + 1, g + l + 1, cmp);
	
	k_func();
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}