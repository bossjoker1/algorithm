// dalao的递归解法
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<const int test_case>// set 8 usually
struct Pollard_Rho {
    vector<long long> fac;
    long long quick_pow(long long a, long long b, long long mod) {
        long long ans = 1;
        while (b) {
            if (b&1) ans = (__int128)ans*(__int128)a%mod;
            b >>= 1, a = (__int128)a*(__int128)a%mod;
        }
        return ans;
    }
    bool Miller_Rabin(long long n) {// return if n is a prime
        if (n < 3) return n == 2;
        long long a = n-1, b = 0;
        while (a%2 == 0) a /= 2, ++b;
        for (int i = 0, j; i < test_case; i++) {
            long long x = rand()%(n-2)+2, v = quick_pow(x, a, n);
            if (v == 1 || v == n-1) continue;
            for (j = 0; j < b; j++) {
                v = (__int128)v*(__int128)v%n;
                if (v == n-1) break;
            }
            if (j >= b) return false;
        }
        return true;
    }
    long long f(long long x, long long c, long long n) { return ((__int128)x * x + c) % n; }
    long long rho(long long x) {
        long long s = 0, t = 0;
        long long c = (__int128)rand() % (x - 1) + 1;
        int step = 0, goal = 1;
        long long val = 1;
        for (goal = 1;; goal <<= 1, s = t, val = 1) {
            for (step = 1; step <= goal; ++step) {
                t = f(t, c, x);
                val = (__int128)val * abs(t - s) % x;
                if ((step % 127) == 0) {
                    long long d = __gcd(val, x);
                    if (d > 1) return d;
                }
            }
            long long d = __gcd(val, x);
            if (d > 1) return d;
        }
    }
    void find(long long x) {
        if (x == 1) return;
        if (Miller_Rabin(x)) {
            fac.push_back(x);
            return;
        }
        long long p = x;
        while (p >= x) p = rho(x);
        //while ((x % p) == 0) x /= p;
        find(x/p), find(p);
    }
    vector<long long> factor(long long n) {// return the factors of n
        srand((unsigned)time(NULL));
        fac.clear();
        find(n);
        sort(fac.begin(), fac.end());
        return fac;
    }
};

ll a, s, m;
int fl = 0;
ll pow(__int128 a, __int128 b, __int128 m) {
    __int128 ans = 1;
    if(a >= m) a %= m, fl = 1;
    int tf = 0;
    while (b) {
        if (b&1) {
            ans = 1ll*ans*a;
            if(ans >= m) ans %= m, fl = 1;
            if(tf) fl = 1;
        }
        b >>= 1, a = 1ll*a*a;
        if(a >= m) a %= m, tf = 1;
    }
    return ans;
}

int main() {
    scanf("%lld%lld%lld", &a, &s, &m);
    Pollard_Rho<8> rho;
    unordered_map<ll, ll> res;
    auto get_phi = [&](ll m) {
                     if(res.count(m)) return res[m];
                     vector<ll> fac = rho.factor(m);
                     fac.erase(unique(fac.begin(), fac.end()), fac.end());
                     ll ret = m;
                     for (auto p : fac) {
                         ret /= p;
                         ret *= (p-1);
                     }
                     return res[m] = ret;
                 };
    ll ans = 0, cur = 0;
    function<ll(ll, int)> dfs = [&](ll m, int dep)->ll {
                                   if(!dep) return 1;
                                   if(!m) return 1;
                                   ll pm = get_phi(m);
                                   ll t = dfs(pm, dep-1);
                                   fl = 0;
                                   ll ret = pow(a, t, m);
                                   return ret+m*fl;
                           };
    
    for (ll i = 1; i <= s; i++) {
        ll now = dfs(m, i);
        if(now == cur) {
            (ans += ((__int128)(s-i+1)%m*(__int128)now%m)%m) %= m;
            break;
        }
        (ans += now) %= m;
        cur = now;
    }
    printf("%lld\n", ans);
    return 0;
}