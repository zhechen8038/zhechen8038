#include<bits/stdc++.h>
using namespace std;


int func(int a[],int left,int right,int k){
	if(a[left]==k){
		return left+1;
	}
	while(left<right){
		int mid=(left+right)/2;
		if(a[mid]==k){
			right=mid;
		}
		else if(a[mid]>k) right=mid-1;
		else left=mid+1;
	}
	if(a[left]!=k) return -1;
	return left+1;
}
int main(){
	int n,m;
	cin>>n>>m;
	int a[n];
	int q[m];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		cin>>q[i];
	}
	for(int i=0;i<m;i++){
		cout<<func(a,0,n-1,q[i])<<" ";
	}
	return 0;
}