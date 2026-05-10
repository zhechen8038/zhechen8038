#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	
	int t;
	cin>>t;
	
	while(t--){
		int n;
		cin>>n;
		
		vector<int> a(n);
		rep(i,n) cin>>a[i];
		
		vector<int> premin(n),premax(n);
		
		premin[0]=a[0];
		for(int i=1;i<n;i++){
			premin[i]=min(premin[i-1],a[i]);
		}
		
		premax[n-1]=a[n-1];
		for(int i=n-2;i>=0;i--){
			premax[i]=max(premax[i+1],a[i]);
		}
		
		rep(i,n){
			if(i==0||i==n-1){
				cout<<"1";
				continue;
			}
			if(a[i]<=premin[i]){
				cout<<"1";
			} 
			
			else if(a[i]>premin[i]&&a[i]>=premax[i]){
				cout<<"1";
			}
			else{
				cout<<"0";
			}
		}
		cout<<"\n";
	}
	
	return 0;
}