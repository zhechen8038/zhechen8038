#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,b) for(int i=a;i<=b;i++)

const int MAX=1e5+1;

struct node{
	vector<int> t;
	int size;
};

int n,m;
vector<node> g(MAX);//邻接表
vector <int> a(MAX,0);//能到达最大的值

void dfs(int x,int ans){//ans是当前最大值
	if(a[x]) return;//访问过了
	a[x]=ans;
	
	rep(i,0,g[x].size-1){
		dfs(g[x].t[i],ans);//能到达他的点的最大值都为ans
	}
	
}

void solve(){
	cin>>n>>m;
	
	rep(i,1,m){
		int u,v;
		cin>>u>>v;
		g[v].t.push_back(u);//反向建边
		g[v].size++;
	}
	
	for(int i=n;i>=1;i--){
		dfs(i,i);
	}
	
	rep(i,1,n){
		cout<<a[i]<<" ";
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	solve();
}