#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;i++)

const int MAX=1010;

int n;
int res[MAX]; // res代表结果
int a[MAX]; // a代表底数

void muti1(){
	int temp[MAX]={0}; // temp[1]表示10位上的数字，temp[2]表示100位上的数字...
	
	rep(i,500){
		rep(j,500){
			temp[i+j]+=res[i]*a[j];
		}
	}
	
	int t=0; // 表示进位
	rep(i,500){
		temp[i]+=t; // 加上一个进位
		res[i]=temp[i]%10;
		t=temp[i]/10;
	}
}

void muti2(){
	int temp[MAX]={0}; // temp[1]表示10位上的数字，temp[2]表示100位上的数字...
	
	rep(i,500){
		rep(j,500){
			temp[i+j]+=a[i]*a[j];
		}
	}
	
	int t=0; // 表示进位
	rep(i,500){
		temp[i]+=t; // 加上一个进位
		a[i]=temp[i]%10;
		t=temp[i]/10;
	}
}

void fast_pow(int p){
	res[0]=1,a[0]=2; // 初始化
	while(p>0){
		if(p&1){
			muti1(); // res*a
		}
		muti2(); // a*a
		p>>=1; // 右移
	}
}

void solve(){
	cin>>n;
	int len=n*log10(2)+1;
	fast_pow(n);
	
	cout<<len<<"\n";
	
	int k=0;
	res[0]-=1;
	for(int i=499;i>=0;i--){
		if(k==50){
			cout<<"\n";
			k=0;
		}
		cout<<res[i];
		k++;
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
}