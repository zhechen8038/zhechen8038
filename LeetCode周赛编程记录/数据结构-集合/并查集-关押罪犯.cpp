//总结：a[i]只能当做当前的i的祖先，但是判断两个数i,j是否为在同一个集合，
//要判断他们的集合的祖先是否是同一个祖先，要用zfind函数查找
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,b) for(int i=a;i<=b;i++)

const int MAX=100005;

struct abj{
	int x;
	int y;
	int w;
};

abj aj[MAX];
int a[MAX],b[MAX];//a[i]代表i的祖先，b[i]代表i的敌人

int zfind(int x){
	if(a[x]==x){
		return x;
	}
	return a[x]=zfind(a[x]);
}

int zcheck(int x,int y){
	int x1=zfind(x),y1=zfind(y);
	return x1==y1;
}

void zadd(int x,int y){
	int x1=zfind(x),y1=zfind(y);
	a[x1]=y1;
}

bool cmp(const abj& a,const abj& b){
	return a.w>b.w;
}

void solve(){
	int n,m;
	cin>>n>>m;
	
	rep(i,1,n) a[i]=i;
	
	rep(i,1,m){
		cin>>aj[i].x>>aj[i].y>>aj[i].w;
	}
	
	//贪心：从大到小分组
	sort(aj+1,aj+m,cmp);
	
	rep(i,1,m){
		if(zcheck(aj[i].x,aj[i].y)){//在之前最优的情况下分到了一组，不可避免输出该值，并且该值最大
			cout<<aj[i].w;
			return;
		}
		
		//不在一组就对立
		if(!b[aj[i].x]){//没有敌人，他就是敌人
			b[aj[i].x]=aj[i].y;
		}
		else{//有敌人，将他和敌人分在一组
			zadd(b[aj[i].x],aj[i].y);
		}
		
		if(!b[aj[i].y]){//没有敌人，他就是敌人
			b[aj[i].y]=aj[i].x;
		}
		else{//有敌人，将他和敌人分在一组
			zadd(b[aj[i].y],aj[i].x);
		}
		
	}
	
	cout<<0;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	solve();
}