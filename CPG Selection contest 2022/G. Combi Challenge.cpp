#include "bits/stdc++.h"
using namespace std;

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

mint ncr (int n, int r) {
	assert(r <= 50);

	if (n < r or r < 0) return 0;

	mint v = 1;
	for (int i = 0; i < r; i++)
		v *= (n - i), v /= (r - i);

	return v;
}


int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, k; cin >> n >> k;

    vector a(k, 0); cin >> a;

    mint v = 0;

    for (int m = 0; m < (1 << k); m++) {
    	long long N = n;
    	bool minus = false;
    	for (int bit = 0; bit < k; bit++) if ((m >> bit) & 1)
    		minus ^= 1, N -= a[bit];

        if (N >= 0)
    	   v += ncr(N + k - 1, k - 1) * (minus? -1 : 1);
    }

    cout << v;

}