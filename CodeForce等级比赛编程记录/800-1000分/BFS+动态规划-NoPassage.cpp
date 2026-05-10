#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);i++)
const int dx[4]={0,0,-1,1};
const int dy[4]={-1,1,0,0};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	
	int h,w,k;
	cin>>h>>w>>k;
	
	vector<vector<int>> dp(h,vector<int>(w,-1));
	vector<vector<int>> cnt(h,vector<int>(w,0));
	queue<pair<int,int>> q;
	rep(i,k){
		int r,c;
		cin>>r>>c;
		r--;c--;
		dp[r][c]=0;
		q.push({r,c});
	}
	
	//如果两次访问，即两个方向可打通
	while(!q.empty()){
		pair<int,int> cur=q.front();
		q.pop();
		int x=cur.first;
		int y=cur.second;
		
		int d=dp[x][y];
		rep(i,4){
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(nx<0||nx>=h||ny<0||ny>=w) continue;
			if(dp[nx][ny]==-1){
				cnt[nx][ny]++;
				if(cnt[nx][ny]==2){
					dp[nx][ny]=d+1;
					q.push({nx,ny});
				}
			}
		}
	}
	
	ll ans=0;
	rep(i,h){
		rep(j,w){
			if(dp[i][j]!=-1){
				ans+=dp[i][j];
			}
		}
	}
	cout<<ans;
	return 0;
	
}