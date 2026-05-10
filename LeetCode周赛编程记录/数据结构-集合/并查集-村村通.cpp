#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,b) for(int i=a;i<=b;i++)

const int MAX=6000;
vector<int> f(MAX);

int zfind(int x){
	if(f[x]==x){
		return x;
	}
	
	return f[x]=zfind(f[x]);
}

void solve(){
	int n,m;
	
	while(1){
		cin>>n;
		if(n==0) break;
		cin>>m;
		
		int ans=n-1;//假设全部连接，有n-1条路
		//祖先是自己
		rep(i,1,n) f[i]=i;
		
		rep(i,1,m){
			int a,b;
			cin>>a>>b;
			
			int x=zfind(a),y=zfind(b);
			if(x==y) continue;//属于同一个集合就跳过
			
			f[x]=y;//合并集合
			ans--;
		}
		
		cout<<ans<<"\n";
	}
	
	
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	solve();
}