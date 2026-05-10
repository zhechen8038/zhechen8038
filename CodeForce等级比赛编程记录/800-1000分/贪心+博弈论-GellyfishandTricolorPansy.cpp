#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

void solve(){
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	if(d==1||b==1){
		cout<<"Gellyfish";
		return;
	}
	if(a==1||c==1){
		cout<<"Flower";
		return;
	}
	if(c>=b&&a>=d){
		cout<<"Gellyfish";
		return;
	}
	if(c>=b&&a<d&&a>=b){
		cout<<"Gellyfish";
		return;
	}
	if(c<b&&c>=d&&a>=d){
		cout<<"Gellyfish";
		return;
	}
	cout<<"Flower";
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
		cout << "\n";
	}
	return 0;
}