#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;i++)

const int dx[8]={1,2,-1,-2,1,2,-1,-2};
const int dy[8]={2,1,2,1,-2,-1,-2,-1};

void solve(){
	int n,m,x,y;
	cin>>n>>m>>x>>y;
	vector<vector<int>> a(n+1,vector<int>(m+1,-1));
	vector<vector<int>> visited(n+1,vector<int>(m+1,0));
	
	a[x][y]=0;
	visited[x][y]=1;
	queue<pair<int,int>> q;
	q.push({x,y});
	
	
	while(!q.empty()){
		pair<int,int> cur=q.front();
		q.pop();
		int x1=cur.first,y1=cur.second;
		
		rep(i,8){
			int x2=x1+dx[i];
			int y2=y1+dy[i];
			
			if(x2>=1&&x2<=n&&y2>=1&&y2<=m){
				if(!visited[x2][y2]){
					a[x2][y2]=a[x1][y1]+1;
					visited[x2][y2]=1;
					q.push({x2,y2});
				}
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int t=1;
	while(t--){
		solve();
		cout<<"\n";
	}
}