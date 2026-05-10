#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,c;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>c;
	
	sort(a,a+n);
	int res=0;
	int l=0,r=n-1;
	while(l<=r){
		if(a[l]+a[r]<=c) l++;
		r--;
		res++;
	}
	cout<<res;
	return 0;
}