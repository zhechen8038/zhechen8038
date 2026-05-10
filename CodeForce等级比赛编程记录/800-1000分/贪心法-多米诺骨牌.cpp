//贪心策略：每次将尽可能大的骨牌放在最后


#include<bits/stdc++.h>
using namespace std;


int solve(vector<int> &a,int n){
	vector<int> used(n,0);
	
	int last=0;
	int ans=2;
	
	while(1){
		if(2*a[last]>=a[n-1]) return ans;
		
		int next=last;
		int max=a[last];
		for(int i=1;i<n-1;i++){
			if(!used[i]&&a[i]>a[last]&&a[i]<=2*a[last]){
				if(a[i]>max){
					max=a[i];
					next=i;
				}
			}
		}
		
		if(next==last) return -1;
		
		used[next]=1;
		last=next;
		ans++;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		
		vector<int> a(n);
		for(int j=0;j<n;j++){
			cin>>a[j];
		}
		
		int res=solve(a,n);
		
		cout<<res<<"\n";
	}
	
	return 0;
}