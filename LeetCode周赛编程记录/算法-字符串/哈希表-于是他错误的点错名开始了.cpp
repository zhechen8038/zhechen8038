#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 5;

// struct trie{
	// int nex[N][26], cnt;
	// bool exist[N];
	// int vis[N];
//     
	// void insert(string s, int l){
		// int p = 0;
		// for(int i = 0; i < l; i ++){
			// int c = s[i] - 'a';
			// if(!nex[p][c]) nex[p][c] = ++cnt;
			// p = nex[p][c];
		// }
		// exist[p] = true;
	// }
// 	
	// int find(string s, int l){
// 		
		// int p = 0;
		// for(int i = 0; i < l; i ++){
			// int c = s[i] - 'a';
			// if(!nex[p][c]) return 0;
			// p = nex[p][c];
		// }
// 		
		// if(exist[p]){
			// if(vis[p]) return 2;
			// else{
				// vis[p] = 1;
				// return 1;
			// }
		// }
		// else{
			// return 0;
		// }
	// }
// 	
// };

int n, m;
//trie t;
unordered_set<string> t;
unordered_set<string> used;

void solve(){
	cin >> n;
	for(int i = 0; i < n; i ++){
		string s;
		cin >> s;
		t.insert(s);
	}
	cin >> m;
	for(int i = 0; i < m; i ++){
		string s;
		cin >> s;
		if(!t.count(s)){
			cout << "WRONG\n";
		}
		else if(used.count(s)){
			cout << "REPEAT\n";
		}
		else{
			used.insert(s);
			cout << "OK\n";
		}
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}