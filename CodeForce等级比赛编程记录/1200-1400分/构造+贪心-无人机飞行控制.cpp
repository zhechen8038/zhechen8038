#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;i++)

void solve(){
	int n;
	cin>>n;
	vector<int> d(n);
	rep(i,n) cin>>d[i];
	vector<pair<int,int>> a(n);
	rep(i,n) cin>>a[i].first>>a[i].second;
	
	int base=0;
	vector<int> last;
	
	rep(i,n){
		int l=a[i].first,r=a[i].second;
		if(d[i]==-1){
			last.push_back(i);
		}
		else{
			base+=d[i];
		}
		
		while(base<l){
			if(last.empty()){
				cout<<-1;
				return;
			}
			d[last.back()]=1;
			base++;
			last.pop_back();
		}
		
		while(base+(int)last.size()>r){
			if(last.empty()){
				cout<<-1;
				return;
			}
			d[last.back()]=0;
			last.pop_back();
		}
	}
	
	//有些还没有动的就不用改变赋值为0
	rep(i,n) cout<<max(0,d[i])<<" ";
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int t;
	cin>>t;
	
	while(t--){
		solve();
		cout<<"\n";
	}
}