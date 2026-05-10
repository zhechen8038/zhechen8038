#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=1;i<=n;i++)

const int MAX=105;
const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,1,-1};

int n,m;
int a[MAX][MAX];
int vis[MAX][MAX];
int dp[MAX][MAX];
int ans;

void dfs(int x,int y){
	if(vis[x][y]) return;
	vis[x][y]=1;
	
	int mx=0;
	for(int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		
		if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&a[x][y]>a[nx][ny]){
			dfs(nx,ny);
			mx=max(mx,dp[nx][ny]);
		}
	}
	
	dp[x][y]+=mx+1;
	ans=max(ans,dp[x][y]);
}

void solve(){
	cin>>n>>m;
	rep(i,n){
		rep(j,m){
			cin>>a[i][j];
		}
	}
	
	rep(i,n){
		rep(j,m){
			dfs(i,j);
		}
	}
	
	cout<<ans;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}