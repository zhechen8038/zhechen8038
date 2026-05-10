#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(n);i++)

void solve(){
	int l1, b1, l2, b2, l3, b3;
    cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
    int area = l1*b1 + l2*b2 + l3*b3;
    int side = sqrt(area);
    if(side*side!=area){
    	cout<<"NO";
    	return;
    }
    
    if(l1>b1){
    	if(l1==l2&&l2==l3&&b1+b2+b3==l1){
    		cout<<"YES";
    	}
    	else if(l2+l3==l1&&b2==b3&&b1+b2==l1){
    		cout<<"YES";
    	}
    	else{
    		cout<<"NO";
    	}
    }
    else if(l1<b1){
    	if(b1==b2&&b2==b3&&l1+l2+l3==b1){
    		cout<<"YES";
    	}
    	else if(b2+b3==b1&&l2==l3&&l1+l2==b1){
    		cout<<"YES";
    	}
    	else{
    		cout<<"NO";
    	}
    }
    else cout<<"NO";
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	int t;
	cin>>t;
	
	while(t--){
		solve();
		cout<<"\n";
	}
	return 0;
}