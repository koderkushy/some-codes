#include "bits/stdc++.h"

using namespace std;

#define pb                  push_back
#define all(x)              x.begin(), x.end()

template <typename A> istream& operator>> (istream& cin, vector<A> &x){for(int i = 0; i < x.size()-1; i++) cin >> x[i]; return cin >> x[x.size()-1];}

template<uint32_t MOD>
class Mint {
  public:
    using internal_value_type = int;
    static_assert(int(MOD) >= 1, "MOD is less than 1");
    static Mint raw (uint32_t v) { return *reinterpret_cast<Mint*>(&v); }
    static constexpr int getmod () { return MOD; }
    constexpr Mint (int64_t v) : val((v %= MOD) < 0 ? v + MOD : v) {}
    constexpr Mint () : val(0) {}
    template<class T> constexpr explicit operator T() const { return val; }
    constexpr int get () const { return val; };
    constexpr Mint& operator++ () { return val = ++val == MOD ? 0 : val, *this; }
    constexpr Mint& operator-- () { return --(val ? val : val = MOD), *this; }
    constexpr Mint operator+ () const { return *this; }
    constexpr Mint operator- () const { return raw(val ? MOD - val : 0); }
    constexpr Mint& operator+= (const Mint o) { return val = int(val += o.val - MOD) < 0 ? val + MOD : val, *this; }
    constexpr Mint& operator-= (const Mint o) { return val = int(val -= o.val) < 0 ? val + MOD : val, *this; }    
    constexpr Mint& operator*= (const Mint &o) { return val = fast_mod(static_cast<uint64_t>(val) * o.val), *this; }
    constexpr Mint& operator/= (const Mint &o) { return *this *= o.inv(); }
    constexpr friend Mint operator+ (Mint a, Mint b) { return a += b; }
    constexpr friend Mint operator- (Mint a, Mint b) { return a -= b; }
    constexpr friend Mint operator* (Mint a, Mint b) { return a *= b; }
    constexpr friend Mint operator/ (Mint a, Mint b) { return a /= b; }
    constexpr friend Mint operator++ (Mint& a, int) { return std::exchange(a, ++Mint(a)); }
    constexpr friend Mint operator-- (Mint& a, int) { return std::exchange(a, --Mint(a)); }
    constexpr friend bool operator== (Mint a, Mint b) { return a.val == b.val; }
    constexpr friend bool operator!= (Mint a, Mint b) { return a.val != b.val; }
    constexpr Mint inv () const { return extgcd(val, MOD); }
    constexpr Mint pow (uint64_t p) {
        assert(p >= 0);
        Mint a = *this, res = 1;
        while (p > 0) {
            if (p & 1) res *= a;
            a *= a, p >>= 1;
        }
        return res;
    }
    constexpr friend std::istream& operator>>(std::istream& is, Mint& x) { int64_t v; return is >> v, x = v, is; }
    constexpr friend std::ostream& operator<<(std::ostream& os, Mint x) { return os << x.val; }
  private:
    int val;
    static unsigned fast_mod (uint64_t x, unsigned m = MOD) {
        #if !defined(_WIN32) || defined(_WIN64)
            return x % m;
        #endif
        unsigned x_high = x >> 32, x_low = (unsigned) x; unsigned quot, rem;
        asm("divl %4\n": "=a" (quot), "=d" (rem): "d" (x_high), "a" (x_low), "r" (m));
        return rem;
    }
    constexpr static int extgcd(int a, int b) {
        std::array x{1, 0};
        while (b) std::swap(x[0] -= a / b * x[1], x[1]), std::swap(a %= b, b);
        return x[0];
    }
};
using mint = Mint<998244353>;


void darling(int kase){

    int n; cin >> n;

    vector a(n, 0); cin >> a;
    vector l(n, 0);

    {
        int i = 0, j = 1, xr = a[0];
        while (j < n) {
            while (xr & a[j])
                xr ^= a[i++];
            l[j] = i, xr |= a[j++];
        }
    }

    vector p(n, mint()), dp(n, mint(1));
    dp[0] = 1, p[0] = 1;

    for (int i = 1; i < n; i++) {
        dp[i] = p[i-1];
        if (l[i] == 0) dp[i]++;
        if (l[i] > 1) dp[i] -= p[l[i] - 2];
        p[i] = p[i-1] + dp[i];
    }

    cout << dp[n-1] << '\n';

}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);


    int T; cin >> T;
    for(int K = 0; K < T; K++)
        darling(K+1);

}