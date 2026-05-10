#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=1;i<=n;i++)

const int MAX=1e5+5;

int n,q;
int d[MAX],c[MAX];
int nxt[MAX][20]; // 表示从编号为i的盘子2^j步到达的编号
int sum[MAX][20]; // 表示区间总水量

// 查找比自己大的盘子
void find_mx(){
	stack<int> stk; // 单调栈
	
	rep(i,n){
		while(!stk.empty()&&d[i]>d[stk.top()]){
			nxt[stk.top()][0]=i;
			sum[stk.top()][0]=c[i];
			stk.pop();
		}
		stk.push(i);
	}
	
	// 没有找到大的就是池底0
	while(!stk.empty()){
		nxt[stk.top()][0]=0;
		stk.pop();
	}
}

// 初始化跳盘
void pre_rmq(){
	
	for(int j=1;(1<<j)<=n;j++){// 遍历步长
		for(int i=1;i+(1<<j)<=n;i++){// 遍历起跳点
			nxt[i][j]=nxt[nxt[i][j-1]][j-1];
			sum[i][j]=sum[i][j-1]+sum[nxt[i][j-1]][j-1];
		}
	}
}

// 查找
int query(int r,int v){
	if(c[r]>=v){
		return r;
	}
	
	v-=c[r];
	for(int j=18;j>=0;j--){ // 从大往小搜
		if(nxt[r][j]&&sum[r][j]<v){
			v-=sum[r][j];
			r=nxt[r][j];
		}
	}
	
	return nxt[r][0];
}

void solve(){
	cin>>n>>q;
	rep(i,n) cin>>d[i]>>c[i];
	find_mx();
	pre_rmq();
	rep(i,q){
		int r,v;
		cin>>r>>v;
		int ans=query(r,v);
		cout<<ans<<"\n";
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
}