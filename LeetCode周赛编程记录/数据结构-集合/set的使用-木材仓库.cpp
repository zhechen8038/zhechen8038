#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,b) for(int i=a;i<=b;i++)

void solve(){
	int m;
	cin>>m;
	
	set<ll> a;//自动升序和去重
	
	while(m--){
		int op;
		ll len;
		cin>>op>>len;
		
		if(op==1){
			if(a.count(len)){
				cout<<"Already Exist\n";
			}
			else{
				a.insert(len);
			}
		}
		else{
			if(a.empty()){
				cout<<"Empty\n";
				continue;
			}
			
			auto it=a.lower_bound(len);//找到>=len的第一个值
			ll res;
			if(it==a.begin()){//所有元素都比len大
				res=*it;
			}
			else if(it==a.end()){//所有元素都比len小
				res=*prev(it);//it的前一个元素
			}
			else{
				ll up=*it,down=*prev(it);
				if(abs(up-len)<abs(down-len)){
					res=up;
				}
				else{
					res=down;
				}
			}
			cout<<res<<"\n";
			a.erase(res);//删除元素
		}
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	solve();
}