#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
	int m,n;
	cin>>m>>n;
	vector<int> a(m);
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	unordered_set<int> elements(a.begin(),a.end());
	for(int i=0;i<n;i++){
		int q;
		cin>>q;
		if(elements.find(q)!=elements.end()) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}