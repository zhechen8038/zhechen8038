#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;i++)

string a,b;

void dfs(int x,int y,int p,int q){//[x,y]表示先序遍历范围，[p,q]表示中序遍历范围
	if(x>y||p>q) return;
	int i=b.find(a[x]);
	
	dfs(x+1,x+i-p,p,i-1);//i-p表示左子树的节点个数
	dfs(x+i-p+1,y,i+1,q);
	cout<<a[x];
}

void solve(){
	cin>>b>>a;
	
	int n=a.size();
	
	dfs(0,n-1,0,n-1);
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	solve();
}