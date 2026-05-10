//第k小数（数组是不重复的）
#include<bits/stdc++.h>
using namespace std;

int three(int left,int right,int a[]){
	int mid=left+(right-left)/2;
	int t;
	if(a[left]>a[right]){
		t=a[left];
		a[left]=a[right];
		a[right]=t;
	}
	if(a[mid]>a[right]){
		t=a[mid];
		a[mid]=a[right];
		a[right]=t;
	}
	if(a[left]>a[mid]){
		t=a[left];
		a[left]=a[mid];
		a[mid]=t;
	}
	t=a[mid];
	a[mid]=a[right];
	a[right]=t;
	return a[right];
}
int partion(int left,int right,int a[]){
	int pivot=three(left,right,a);
	int i=left,j=right;
	while(i<j){
		while(i<j&&a[i]<pivot) i++;
		a[j]=a[i];
		while(i<j&&a[j]>=pivot) j--;
		a[i]=a[j];
	}
	a[i]=pivot;
	return i;
}

int find(int left,int right,int a[],int k){
	while(left<right){
		int mid=partion(left,right,a);
		if(mid==k) return a[mid];
		if(mid<k) left=mid+1;
		if(mid>k) right=mid-1;
	}
	return a[left];
}
int main(){
	int n,k;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>k;
	
	int res=find(0,n-1,a,k-1);
	cout<<res;
	return 0;
}