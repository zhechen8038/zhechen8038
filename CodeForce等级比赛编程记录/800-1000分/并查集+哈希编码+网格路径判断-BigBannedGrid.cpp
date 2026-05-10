#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(n);i++)

const int dx[8]={0,0,1,-1,1,-1,1,-1};
const int dy[8]={1,-1,0,0,1,-1,-1,1};

struct DSU{
	vector<int> p;
	DSU(int n):p(n,-1){};
	int find(int x){
		return p[x]<0 ? x:p[x]=find(p[x]);
	}
	void unite(int a,int b){
		a=find(a);b=find(b);
		if(a==b) return;
		if(p[a]>p[b]) swap(a,b);
		p[a]+=p[b];
		p[b]=a;
	}
};

int main(){
	int h,w,k;
	cin>>h>>w>>k;
	
	//虚拟节点
	const int t=k+0;
	const int b=k+1;
	const int l=k+2;
	const int r=k+3;
	
	DSU dsu(k+4);
	
	
// 	重点：利用哈希表将二维坐标点映射到障碍点所对应的编号上，为后面的查找[nx,ny]所对应的障碍点的编号做基础
	// 存障碍点到编号
    unordered_map<long long, int> mp;
    mp.reserve(k * 2);

    auto encode = [&](int r, int c){
        // 把 (r,c) 编码到一个 long long 上
        return (long long)r << 32 | (unsigned long long)c;
    };
    
    
    
	
	vector<pair<int,int>> obs(k);
	rep(i,k){
		int x,y;
		cin>>x>>y;
		obs[i]={x,y};
		mp[encode(x,y)]=i;
		
		if(x==1) dsu.unite(i,t);
		if(x==h) dsu.unite(i,b);
		if(y==1) dsu.unite(i,l);
		if(y==w) dsu.unite(i,r);
	}
	
	rep(i,k){
		pair<int,int> cur=obs[i];
		int x,y;
		x=cur.first;
		y=cur.second;
		
		rep(j,8){
			int nx,ny;
			nx=x+dx[j];
			ny=y+dy[j];
			
			auto it=mp.find(encode(nx,ny));
			if(it!=mp.end()){
				dsu.unite(i,it->second);
			}
		}
	}
	
	
	if(dsu.find(t)==dsu.find(b)||dsu.find(l)==dsu.find(r)||dsu.find(t)==dsu.find(l)||dsu.find(b)==dsu.find(r)){
		cout<<"No";
	}
	else cout<<"Yes";
	
	return 0;
}