#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(n);i++)

struct node{
	int c;
	int x;
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	int q;
	cin>>q;
	
	queue<node> a;
	rep(i,q){
		int k;
		cin>>k;
		if(k==1){
			int c1,x1;
			cin>>c1>>x1;
			node n;
			n.c=c1;n.x=x1;
			a.push(n);
		}
		else if(k==2){
			int c1;
			cin>>c1;
			ll sum=0;
			while(c1&&!a.empty()){
				node& cur=a.front();
				if(cur.c>c1){
					sum+=(ll)c1*cur.x;
					cur.c-=c1;
					break;
				}
				sum+=(ll)cur.c*cur.x;
				c1-=cur.c;
				a.pop();
			}
			cout<<sum<<"\n";
		}
	}
	return 0;
}