// 给定由n个整数（可能为负数）组成的序列a1,a2,...,an，求该序列子段和的最大值。当所有整数均为负数时，其最大子段和为0。
// 
// 【输入】
// 第一行一个整数，表示n的值, 1<=n<=100;
// 第二行n个整数，表示a1,a2,...,an的值。
// 
// 【输出】
// 一个整数，表示最大子段和
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n+1];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	int max_courent=0;
	int ans=0;
	for(int i=0;i<n;i++){
		max_courent=max(0,max_courent+a[i]);
		ans=max(ans,max_courent);
	}
	cout<<ans;
	return 0;
}