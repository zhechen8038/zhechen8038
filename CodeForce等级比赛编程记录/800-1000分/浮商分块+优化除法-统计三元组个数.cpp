#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);i++)
const ll M=998244353;

// 快速取模乘：(__int128)a * b % M
inline ll mul_mod(ll a, ll b) {
    return (ll)((__int128)a * b % M);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	ll n;
	cin>>n;
	// inv2 = (M+1)/2 对 998244353 来说是 499122177
    const ll inv2 = 499122177;

    // ans = n*(n-1)/2 mod M
    ll ans = mul_mod( mul_mod(n % M, (n-1) % M), inv2 );
    
	ll l,r,q;
	for(l=1;l<=n;l=r){
		q=n/l;
		r=n/q+1;
		
		ll cnt=((r-l)%M)*((q-1)%M)%M;//r-l个商为q的b
		ans=(ans-cnt+M)%M;
	}
	cout<<ans;
}