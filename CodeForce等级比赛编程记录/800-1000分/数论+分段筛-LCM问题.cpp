#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 简单埃式筛：返回 [2..N] 内所有质数
vector<int> simple_sieve(int N) {
    vector<char> is_prime(N+1, true);
    vector<int> primes;
    if (N < 2) return primes;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= N; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += i)
                is_prime[j] = false;
        }
    }
    for (int i = 2; i <= N; ++i)
        if (is_prime[i])
            primes.push_back(i);
    return primes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll L, R;
    cin >> L >> R;
    if (L > R) swap(L, R);

    // 1) 枚举小质数 up to sqrt(R)
    int S = floor(sqrt((long double)R));
    vector<int> primes = simple_sieve(S);

    // 2) 区间筛：标记 (L, R] 中的合数，得到区间内的质数
    ll low = L + 1, high = R;
    ll len = max(0LL, high - low + 1);
    vector<char> is_prime_seg(len, true);

    if (len > 0) {
        for (int p : primes) {
            ll start = max<ll>((low + p - 1) / p * p, (ll)p * p);
            for (ll x = start; x <= high; x += p) {
                is_prime_seg[x - low] = false;
            }
        }
        // 如果区间包含 1，就把它标成合数
        if (low == 1) is_prime_seg[0] = false;
    }

    // 统计 k=1 的质数个数
    ll cnt_k1 = 0;
    for (char c : is_prime_seg) {
        if (c) ++cnt_k1;
    }

    // 3) 枚举所有 k>=2 的质数幂
    vector<char> is_ppower(len, false);
    for (int p : primes) {
        ll t = (ll)p * p;
        while (t <= R) {
            if (t > L) {
                // t 属于 (L, R] 时，标记下标 t-low
                is_ppower[t - low] = true;
            }
            // 防止溢出，并加速退出
            if (R / t < p) break;
            t *= p;
        }
    }
    ll cnt_k2plus = 0;
    for (char c : is_ppower) {
        if (c) ++cnt_k2plus;
    }

    // 4) 答案 = 初始的 A_L（算作 1）+ 区间内所有质数（k=1）+ 所有高阶幂（k>=2）
    ll answer = 1 + cnt_k1 + cnt_k2plus;
    cout << answer << "\n";
    return 0;
}
