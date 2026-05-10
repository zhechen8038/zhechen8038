#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> prefix(string s){
	int n = s.size();
	vector<int> res(n);
	
	res[0] = 0;
	for(int i = 1; i < n; i ++){
		int j = res[i - 1];
		while(j > 0 && s[j] != s[i]) j = res[j - 1];
		if(s[j] == s[i]) j ++;
		res[i] = j;
	}
	return res;
}

void find(string text, string pattern){
	string cur = pattern + "#" + text;
	int n1 = pattern.size(), n2 = text.size();
	vector<int> pre = prefix(cur);
	for(int i = n1 + 1; i < n1 + n2 + 1; i ++){
		if(pre[i] == n1) cout << i - 2*n1 + 1 << "\n";
	}
}

void solve(){
	string s1,s2;
	cin >> s1 >> s2;
	find(s1, s2);
	vector<int> ans = prefix(s2);
	for(int x: ans) cout << x << " ";
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}