#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);i++)


void solve(){
	int n;
	cin>>n;
	ll count=0;
	string s="";
	vector<pair<char,ll>> a(n);
	rep(i,n){
		cin>>a[i].first>>a[i].second;
		count+=a[i].second;
		if(count>100){
			cout<<"Too Long";
			return;
		}
		string ch(a[i].second,a[i].first);
		s+=ch;
	}
	cout<<s;
}



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}