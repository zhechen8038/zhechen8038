#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,b) for(int i = a; i <= b; i++)

const int MAX=2e5+5;
int f[MAX];
unordered_map<int,int> id;//原编号->新编号,离散化
int cnt;//当前编号个数

int zfind(int x){
	if(f[x]==x) return x;
	return f[x]=zfind(f[x]);
}

int check(int x,int y){
	return zfind(x)==zfind(y);
}

int get_id(int x){
	if(id.count(x)) return id[x];
	return id[x]=cnt++;
}

void unit(int x,int y){
	int x1=zfind(x),y1=zfind(y);
	if(x1!=y1) f[x1]=y1;
}

void solve(){
	int n;
	cin>>n;
	
	id.clear();
	cnt=0;
	
	vector<pair<int,int>> eq,neq;
	
	rep(i,1,n){
		int x,y,z;
		cin>>x>>y>>z;
		int idx=get_id(x);
		int idy=get_id(y);
		
		if(z==1){
			eq.push_back({idx,idy});
		}
		else{
			neq.push_back({idx,idy});
		}
	}
	
	rep(i,0,cnt-1){
		f[i]=i;
	}
	
	for(const pair<int,int>& p:eq){
		int x=p.first,y=p.second;
		unit(x,y);
	}
	
	bool ans=true;
	for(const pair<int,int>& p:neq){
		int x=p.first,y=p.second;
		if(check(x,y)){
			ans=false;
			break;
		}
	}
	
	if(ans){
		cout<<"YES";
	}
	else{
		cout<<"NO";
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t;
	cin>>t;
	
	while(t--){
		solve();
		cout<<"\n";
	}
}