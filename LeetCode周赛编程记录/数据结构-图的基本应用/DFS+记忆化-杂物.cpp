#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,b) for(int i=a;i<=b;i++)

const int MAX=1e4+1;

struct node{
	int t;
	vector<int> a;
	int size;
};

int n;
node g[MAX];
vector<int> mx(MAX,0);

void dfs(int x){
	if(mx[x]) return;
	mx[x]+=g[x].t;
	
	int mx1=0;
	rep(i,0,g[x].size-1){
		dfs(g[x].a[i]);
		mx1=max(mx1,mx[g[x].a[i]]);
	}
	mx[x]+=mx1;
}

void solve(){
	cin>>n;
	
	rep(i,1,n){
		int id;
		cin>>id;cin>>g[id].t;
		while(1){
			int x;
			cin>>x;
			if(x==0) break;
			g[id].a.push_back(x);
			g[id].size++;
		}
	}
	
	for(int i=n;i>=1;i--){
		dfs(i);
	}
	
	int ans=0;
	rep(i,1,n){
		ans=max(ans,mx[i]);
	}
	
	cout<<ans;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	solve();
}