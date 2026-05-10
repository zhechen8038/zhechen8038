#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 250000;

struct Eage{
	int u, v, w;
};

int a, b, l;
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

void k_func(){
	int tot = 0;
	int ans = 0;
	
	for(int i = 1; i <= l; i ++){
		int x = g[i].u, y = g[i].v, z = g[i].w;
		int fx = findz(x), fy = findz(y);
		if(fx != fy){
			tot ++;
			ans += z;
			merge(x, y);
		}
	}
	
	cout << ans;
}

void solve(){
	cin >> a >> b;
	
	for(int i = 0; i <= b; i ++){
		fa[i] = i;
	}
	
	for(int i = 0; i <= b; i ++){
		for(int j = 1; j <= b; j ++){
			int x;
			x = a;
			if(i != 0) cin >> x;
			if(x != 0){
				l++;
				g[l].u = i;
				g[l].v = j;
				g[l].w = x;	
			}
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