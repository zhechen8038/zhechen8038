#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,b) for(int i = a; i <= b; i++)

const int INF=1e5;
const int MAX=125;

int n;
int a[MAX][MAX];
int b[MAX][MAX];

void solve(){
	cin>>n;
	rep(i,1,n){
		rep(j,1,n){
			cin>>a[i][j];
			b[i][j]=b[i-1][j]+b[i][j-1]-b[i-1][j-1]+a[i][j];
		}
	}
	
	int ans=-INF;
	rep(l,1,n){
		rep(r,1,n){
			rep(i,l,n){
				rep(j,r,n){
					int s=b[i][j]-b[i-l][j]-b[i][j-r]+b[i-l][j-r];
					ans=max(ans,s);
				}
			}
		}
	}
	
	cout<<ans;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}