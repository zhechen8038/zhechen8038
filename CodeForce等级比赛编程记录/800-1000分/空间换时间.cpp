#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[1001];
	memset(a,0,sizeof(a));
	int t;
	int ans=0;
	for(int i=0;i<n;i++){
		cin>>t;
		if(a[t]==0) ans++;
		a[t]=t;
	}
	cout<<ans<<endl;
	for(int i=0;i<1001;i++){
		if(a[i]!=0) cout<<a[i]<<" ";
	}
	return 0;
	
}