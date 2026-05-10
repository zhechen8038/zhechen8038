#include<bits/stdc++.h>
using namespace std;

const int N = 1005;

struct Thing{
	int v, w;
};

int n, m;
int dp[N];
vector<Thing> things[N];

void solve(){
	cin >> m >> n;
	for(int i = 0; i < n; i ++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		things[c].push_back({a, b});
	}
	
	for(int i = 0; i < N; i ++)
	{
		if(!things[i].size()) continue;
		for(int j = m; j >= 0; j --)
			for(auto &p: things[i])
				if(j >= p.v)
					dp[j] = max(dp[j], dp[j - p.v] + p.w);
	}
	
	cout<<dp[m];
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}