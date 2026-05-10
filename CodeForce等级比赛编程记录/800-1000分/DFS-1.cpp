// 已知 n 个整数 x 
// 1
// ​
 // ,x 
// 2
// ​
 // ,⋯,x 
// n
// ​
 // ，以及 1 个整数 k（k<n）。从 n 个整数中任选 k 个整数相加，可分别得到一系列的和。例如当 n=4，k=3，4 个整数分别为 3,7,12,19 时，可得全部的组合与它们的和为：
// 
// 3+7+12=22
// 
// 3+7+19=29
// 
// 7+12+19=38
// 
// 3+12+19=34
// 
// 现在，要求你计算出和为素数共有多少种。
// 
// 例如上例，只有一种的和为素数：3+7+19=29。

#include<bits/stdc++.h>
using namespace std;

int n,k;
int ans=0;
vector<long long> a;
bool func(int n){
	if(n==1) return false;
	if(n==2) return true;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0) return false;
	}
	return true;
}

void dfs(int t,int start,int sum){
	if(t>=k){
		if(func(sum)){
			ans++;
		}
		return;
	}
	for(int i=start;i<n;i++){
		dfs(t+1,i+1,sum+a[i]);
	}
}
int main(){
	cin>>n>>k;
	a.resize(n+1);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	dfs(0,0,0);
	cout<<ans;
	return 0;
	
}