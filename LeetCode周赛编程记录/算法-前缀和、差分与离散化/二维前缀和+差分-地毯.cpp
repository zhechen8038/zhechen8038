#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,b) for(int i = a; i <= b; i++)

const int MAX=1e3+5;

int n,m;
int diff[MAX][MAX];
int cnt[MAX][MAX];

void solve(){
	cin>>n>>m;
	
	//差分
	while(m--){
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		diff[x1][y1]++;
		diff[x1][y2+1]--;
		diff[x2+1][y1]--;
		diff[x2+1][y2+1]++;
	}
	
	//前缀和
	rep(i,1,n){
		rep(j,1,n){
			cnt[i][j]=cnt[i-1][j]+cnt[i][j-1]-cnt[i-1][j-1]+diff[i][j];
		}
	}
	
	rep(i,1,n){
		rep(j,1,n){
			cout<<cnt[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	
	
	
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}