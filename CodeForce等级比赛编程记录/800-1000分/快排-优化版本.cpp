//优化后的快排
#include<bits/stdc++.h>
#include<cstdlib>
#include<ctime>
using namespace std;

//三数取中法
int three(int left,int right,int a[]){
	int mid=left+(right-left)/2;
	int t;
	if(a[mid]>a[right]){
		t=a[mid];
		a[mid]=a[right];
		a[right]=t;
	}
	if(a[left]>a[right]){
		t=a[left];
		a[left]=a[right];
		a[right]=t;
	}
	if(a[left]>a[mid]){
		t=a[mid];
		a[mid]=a[left];
		a[left]=t;
	}
	//将中位数放在末尾
	t=a[mid];
	a[mid]=a[right];
	a[right]=t;
	return a[right];
}

int partion(int left,int right,int a[]){
	// int rand_index=left+rand()%(right-left+1);//随机选择数
	// int t=a[left];
	// a[left]=a[rand_index];
	// a[rand_index]=t;
	
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

void q_sort(int left,int right,int a[]){
	if(left<right){
		int i=partion(left,right,a);
		q_sort(left,i-1,a);
		q_sort(i+1,right,a);
	}
}

int main(){
	// //初始化随机种子
	// srand(time(0));
	
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	q_sort(0,n-1,a);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}