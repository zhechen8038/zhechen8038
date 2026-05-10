#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;i++)

const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
const int INX=305;

struct node {
	int x;
	int y;
	int t;
};

void solve(){
	int m;
	cin>>m;
	vector<vector<int>> time(INX,vector<int>(INX,-1));
	vector<vector<int>> visited(INX,vector<int>(INX,0));
	
	while(m--){
		int sx,sy,st;
		cin>>sx>>sy>>st;
		if(st<time[sx][sy]||time[sx][sy]==-1) time[sx][sy]=st;
		rep(i,4){
			int nx=sx+dx[i],ny=sy+dy[i];
			if(nx>=0&&ny>=0&&(st<time[nx][ny]||time[nx][ny]==-1)) time[nx][ny]=st;
		}
	}
	
	queue<node> q;
	node p;
	p.x=0,p.y=0,p.t=0;
	visited[0][0]=1;
	
	q.push(p);
	
	while(!q.empty()){
		node cur=q.front();
		q.pop();
		
		int sx=cur.x,sy=cur.y,st=cur.t;
		
		rep(i,4){
			int nx=sx+dx[i],ny=sy+dy[i],nt=st+1;
			if(nx>=0&&ny>=0&&!visited[nx][ny]&&(time[nx][ny]==-1||nt<time[nx][ny])){
				node txt;
				txt.x=nx,txt.y=ny,txt.t=nt;
				visited[nx][ny]=1;
				q.push(txt);
				
				if(time[nx][ny]==-1){
					cout<<nt;
					return;
				}
			}
		}
	}
	
	cout<<-1;
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