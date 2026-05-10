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
	int n,m,p;
	cin>>n>>m>>p;
	
	//祖先是自己
	rep(i,0,n) f[i]=i;
	
	rep(i,1,m) {
		int a,b;
		cin>>a>>b;
		
		//合并祖先
		f[zfind(a)]=zfind(b);
	}
	
	rep(i,1,p){
		int a,b;
		cin>>a>>b;
		
		if(zfind(a)==zfind(b)){
			cout<<"Yes\n";
		}
		else{
			cout<<"No\n";
		}
	}
	
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	solve();
}