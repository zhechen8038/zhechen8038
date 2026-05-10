#include<bits/stdc++.h>
using namespace std;


int main(){
	int n;
	cin>>n;
	
	vector<double> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	sort(a.begin(),a.end());
	
	int res=0;
	int i=0,j=n-1;
	while(i<=j){
		if(a[i]+a[j]<=3){
			i++;
		}
		j--;
		res++;
	}
	cout<<res;
	return 0;
}