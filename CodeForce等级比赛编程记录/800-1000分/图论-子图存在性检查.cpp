#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	int n,m;
	cin>>n>>m;
	
	vector<int> a(n);
	rep(i,n) cin>>a[i];
	
	vector<vector<bool>> f(n,vector<bool>(n,false));
	vector<int> deg(n,0);
	rep(i,m){
		int u,v;
		cin>>u>>v;
		u--;v--;
		f[u][v]=true;
		f[v][u]=true;
		deg[u]++;
		deg[v]++;
	}
	
	//初始化
	vector<int> d(n);
	int sum=0;
	rep(i,n){
		if(a[i]%2==0) d[i]=0;
		else d[i]=1;
		sum+=d[i];
	}
	
	//检查
	if(sum==0){
		cout<<"0";
		return 0;
	}
	if(sum%2!=0){
		cout<<"-1";
		return 0;
	}
	rep(i,n){
		if(d[i]>deg[i]){
			cout<<"-1";
			return 0;
		}
	}
	
	//检查子图存在性
	int edges=0;
	vector<bool> matched(n,false);
	vector<int> cur(n);
	rep(i,n) cur[i]=d[i];
	rep(i,n){
		if(cur[i]==0) matched[i]=true;
		if(matched[i]) continue;
		
		rep(j,n){
			if(!matched[i]&&f[i][j]){
				cur[i]--;cur[j]--;
				edges++;
				break;
			}
		}
		
		if(!matched[i]){
			rep(k,n){
				if(f[i][k]){
					if(a[k]%2!=0&&d[k]+1<=a[k]){
						d[k]++;
						cur[i]--;
						matched[i]=true;
						edges++;
						break;
					}
					if(a[k]%2==0&&d[k]+2<=a[k]){
						d[k]+=2;
						cur[i]--;
						cur[k]++;
						matched[i]=true;
						edges++;
						break;
					}
				}
			}
			if(!matched[i]){
				cout<<"-1";
				return 0;
			}
		}
	}

	
	cout<<edges;
	
	return 0;
}