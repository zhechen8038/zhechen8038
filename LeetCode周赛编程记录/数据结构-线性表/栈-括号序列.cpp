#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;i++)

void solve(){
	string s;
	cin>>s;
	
	int n=s.size();
	
	stack<pair<char,int>> q;
	vector<bool> matched(n,false);
	
	rep(i,n){
		if(s[i]=='('||s[i]=='['){
			q.push({s[i],i});
		}
		else{
			if(!q.empty()){
				pair<char,int> cur=q.top();
				char p=cur.first;
				int x=cur.second;
				
				if((p=='('&&s[i]==')')||(p=='['&&s[i]==']')){
					matched[x]=true;
					matched[i]=true;
					q.pop();
				}
			}
		}
	}
	
	string ans="";
	
	rep(i,n){
		if(matched[i]){
			ans+=s[i];
		}
		else{
			if(s[i]=='('||s[i]=='['){
				ans+=s[i];
				if(s[i]=='('){
					ans+=')';
				}
				else{
					ans+=']';
				}
			}
			else{
				if(s[i]==')'){
					ans+='(';
				}
				else{
					ans+='[';
				}
				ans+=s[i];
			}
		}
	}
	
	cout<<ans;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	solve();
}