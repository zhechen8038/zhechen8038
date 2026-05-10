#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2005;

struct trie{
	int nex[N][26], cnt, len_mx;
	bool exist[N];
	
	void insert(string s, int l){
		int p = 0;
		int mx = 1;
		for(int i = 0; i < l; i ++){
			int c = s[i] - 'a';
			if(!nex[p][c]) nex[p][c] = ++cnt;
			p = nex[p][c];
			if(exist[p]) mx++;
		}
		exist[p] = true;
		len_mx = max(len_mx, mx);
	}
};

int n;
trie t;

void solve(){
	cin >> n;
	for(int i = 0; i < n; i ++){
		string s;
		cin >> s;
		t.insert(s, s.size());
	}
	cout << t.len_mx;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}