#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=1;i<=n;i++)

const int MAX=1e6;

struct Node{
	int lc;
	int rc;
};

Node tree[MAX];

int dfs(int node){
	if(tree[node].lc==0&&tree[node].rc==0){
		return 1;
	}
	
	int l=dfs(tree[node].lc);
	int r=dfs(tree[node].rc);
	
	return 1+max(l,r);
}

void solve(){
	int n;
	cin>>n;
	rep(i,n) cin>>tree[i].lc>>tree[i].rc;
	
	int ans=dfs(1);
	
	cout<<ans;
	
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	solve();
}