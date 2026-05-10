#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;i++)

void solve(){
	string s;
	cin>>s;
	int n=s.size();
	
	stack<int> num;
	
	int d=0;
	rep(i,n){
		if(s[i]=='.'){
			num.push(d);
			d=0;
		}
		
		else if(s[i]=='@'){
			if(!num.empty()){
				int ans=num.top();num.pop();
				cout<<ans;
				break;
			}
		}
		
		else if(s[i]>='0'&&s[i]<='9'){
			d=d*10+(s[i]-'0');
		}
		
		else{
			if(num.size()<2) break;
			
			int d2=num.top();num.pop();
			int d1=num.top();num.pop();
			int res;
			
			if(s[i]=='+'){
				res=d1+d2;
			}
			else if(s[i]=='-'){
				res=d1-d2;
			}
			else if(s[i]=='*'){
				res=d1*d2;
			}
			else if(s[i]=='/'){
				if(d1!=0) res=d1/d2;
				else break;
			}
			
			num.push(res);
		}
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	solve();
}