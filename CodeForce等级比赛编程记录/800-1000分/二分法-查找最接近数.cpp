#include<bits/stdc++.h>
using namespace std;

int find(int left,int right,int a[],int k){
	if(a[left]>=k) return a[left];
	if(a[right]<=k) return a[right];
	while(left<=right){
		int mid=left+(right-left)/2;
		if(a[mid]==k) return a[mid];
		else if(a[mid]>k) right=mid-1;
		else left=mid+1;
	}
	if(left>0&&abs(a[left-1]-k)<=abs(a[left]-k)) return a[left-1];
	return a[left];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int m,n;
	cin>>m;
	int a[m];
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	cin>>n;
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		int res=find(0,m-1,a,k);
		cout<<res<<"\n";//使用这个，不会超时
	}
	return 0;
}