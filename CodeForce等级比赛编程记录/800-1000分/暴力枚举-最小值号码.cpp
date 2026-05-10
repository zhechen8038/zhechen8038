#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);i++)


void solve(){
	string s;
	cin>>s;
	vector<int> a(10,0);
	rep(i,10) a[s[i]-'0']++;
	rep(i,10){
		int end=9-i;
		for(int j=end;j<10;j++){
			if(a[j]){
				cout<<j;
				a[j]--;
				break;
			}
		}
	}
}



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int t;
	cin>>t;
	while(t--){
		solve();
		cout<<"\n";
	}
	return 0;
}