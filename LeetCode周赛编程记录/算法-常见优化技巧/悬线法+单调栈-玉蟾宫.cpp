#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX=1005;

int n,m;
int f[MAX][MAX];
int h[MAX];

int get_s(){
	stack<int> st;//存储下标
	
	h[m + 1] = 0; // 哨兵
	
	int mx_area=0;
	for(int i=1;i<=m+1;i++){
		while(!st.empty()&&h[st.top()]>h[i]){
			int high=h[st.top()];
			st.pop();
			
			//顶峰左边元素没有比他矮的，都比他高，即左边可以无限扩展，
			//但存在h[i]比他矮，即右边只能扩展到i-1
			int width;
			if(st.empty()){
				width=i-1;
			}
			else width=i-st.top()-1;
			mx_area=max(mx_area,high*width);
		}
		st.push(i);
	}
	
	return mx_area;
}

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char ch;
			cin>>ch;
			if(ch=='F') f[i][j]=1;
			else f[i][j]=0;
		}
	}
	
	int ans=0;
	
	//计算以每一行为结尾的最大面积
	for(int i=1;i<=n;i++){
		//更新柱状图高度
		for(int j=1;j<=m;j++){
			if(f[i][j]==1){
				h[j]++;
			}
			else h[j]=0;
		}
		
		ans=max(ans,get_s());
	}
	
	cout<<3*ans;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
}