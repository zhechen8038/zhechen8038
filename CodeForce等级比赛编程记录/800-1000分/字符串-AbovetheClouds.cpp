#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(n);i++)


void solve(){
	int n;
	cin>>n;
	string str;
	cin>>str;
	for(int i=1;i<n-1;i++){
		char ch=str[i];
		if(ch==str[0]||ch==str[n-1]){
			cout<<"Yes";
			return;
		}
		for(int j=i+1;j<n-1;j++){
			if(ch==str[j]){
				cout<<"Yes";
				return;
			}
		}
	}
	cout<<"No";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	int t;
	cin>>t;
	
	while(t--){
		solve();
		cout<<"\n";
	}
	return 0;
}