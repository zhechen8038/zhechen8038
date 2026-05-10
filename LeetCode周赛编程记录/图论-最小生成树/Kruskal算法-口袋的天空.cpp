#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e4 + 1;

struct Eage{
	int u, v, w;
};

int n, m, k;
Eage eage[N];
int fa[N];

int findz(int x){
	if(fa[x] == x) return x;
	return fa[x] = findz(fa[x]);
}

void merge(int x, int y){
	int fx = findz(x), fy = findz(y);
	if(fx != fy) fa[fx] = fy;
}

bool cmp(const Eage &a, const Eage &b){
	return a.w < b.w;
}

// Kruskal 算法
void kruskal(){
    int tot = 0, ans = 0;
    
    for(int i = 1; i <= m; i ++){
        int x = eage[i].u, y = eage[i].v, z = eage[i].w;
        int fx = findz(x), fy = findz(y);
        if(fx != fy){
            merge(x, y);
            tot ++;
            ans += z;
            if(tot == n - k) break; // 提前结束
        }
    }
    
    if(tot == n - k) cout << ans;
    else cout << "No Answer";
}


void solve(){
	cin >> n >> m >> k;
	
	for(int i = 1; i <= n; i ++){
		fa[i] = i;
	}
	
	for(int i = 1; i <= m; i ++){
		cin >> eage[i].u >> eage[i].v >> eage[i].w;
	}
	
	sort(eage + 1, eage + m + 1, cmp);
	
	kruskal();
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}