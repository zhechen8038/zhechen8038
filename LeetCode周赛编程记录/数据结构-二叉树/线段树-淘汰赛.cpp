#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=1;i<=n;i++)

struct Node{
	int data;
	int id;
};

Node a[150],tree[600];//a存放数据，tree存放节点

Node tmax(const Node& a,const Node& b){
	return a.data>b.data ? a : b;
}

Node tmin(const Node& a,const Node& b){
	return a.data<b.data ? a : b;
}

//建线段树，从叶节点到根
void build(int node,int begin,int end){//[begin,end]区间的数据，推出最终节点node
	if(begin==end){
		tree[node]=a[begin];
		return;
	}
	
	int lnode=2*node;
	int rnode=2*node+1;
	int mid=(begin+end)/2;
	
	build(lnode,begin,mid);
	build(rnode,mid+1,end);
	
	tree[node]=tmax(tree[lnode],tree[rnode]);
}
void solve(){
	int n;
	cin>>n;
	
	rep(i,(1<<n)){
		cin>>a[i].data;
		a[i].id=i;
	}
	
	build(1,1,(1<<n));
	
	//输出亚军
	Node tans=tmin(tree[2],tree[3]);
	
	cout<<tans.id;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	solve();
}