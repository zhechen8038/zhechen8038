//图的着色问题
#include<bits/stdc++.h>
using namespace std;

int n,e,m;
vector<vector<int>> a;
vector<int> x;

int ans=0;
void NextValue(int k,int m){
	do{
		int j;
		x[k]=(x[k]+1)%(m+1);//判断颜色
		if(!x[k]) return;
		for(j=0;j<k;j++){
			if(a[k][j]&&x[k]==x[j]) break;
		}
		if(j==k) return;//没有冲突就退出
	}while(1);
}
void mColoring(int k,int m){
	do{
		NextValue(k,m);
		if(x[k]==0) break;
		if(k==n-1){
			ans++;
			for(int i=0;i<n;i++){
				cout<<x[i]<<" ";
			}
			cout<<endl;
		}
		else mColoring(k+1,m);//图下一层节点颜色
	}while(1);//外层循环遍历每一种颜色
}
int main(){
	cin>>n>>e>>m;
	a.resize(n,vector<int>(n,0));
	x.resize(n,0);
	for(int i=0;i<e;i++){
		int left,right;
		cin>>left>>right;
		a[left][right]=1;
		a[right][left]=1;
	}
	mColoring(0,m);
	if(ans==0){
		cout<<"No solution";
	}
	return 0;
}