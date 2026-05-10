#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,b) for(int i=a;i<=b;i++)

map<string,int> s;

void solve(){
	int n;
	cin>>n;
	
	while(n--){
		int op;
		cin>>op;
		
		if(op==1){
			string na;
			int sc;
			cin>>na>>sc;
			s[na]=sc;
			cout<<"OK\n";
		}
		else if(op==2){
			string na;
			cin>>na;
			if(s.count(na)){
				cout<<s[na]<<"\n";
			}
			else{
				cout<<"Not found\n";
			}
		}
		else if(op==3){
			string na;
			cin>>na;
			if(s.count(na)){
				s.erase(na);
				cout<<"Deleted successfully\n";
			}
			else{
				cout<<"Not found\n";
			}
		}
		else{
			cout<<s.size()<<"\n";
		}
		
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	solve();
}