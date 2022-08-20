#include "bits/stdc++.h"
using namespace std;

#define all(x)              x.begin(), x.end()

struct DSU{
    std::vector<int> z;

    DSU(int n): z(n, -1) {}

    int head (const int x) {
    	if (z[x] < 0) return x;
    	return z[x] = head(z[x]);
    }

    int size (const int x) {
    	return -z[head(x)];
	}

	std::vector<int> sizes () {
		vector<int> a;
		for (int sz: z)
			if (sz < 0)
				a.push_back(-sz);
		return a;
	}

    bool same (const int x, const int y) {
    	return head(x) == head(y);
    }

    bool unite (const int x, const int y) {
        const int& px = head(x), py = head(y);
        if(px == py) return false;
        if(z[px] > z[py])
        	z[py] += z[px], z[px] = py;
        else
        	z[px] += z[py], z[py] = px;
        return true;
    }
};

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
using mint = Mint<1'000'000'007>;

void darling(int kase){

    int n; cin >> n;

    vector one(30, DSU(n)), zero(30, DSU(n));

    for (int i = 1; i < n; i++) {
    	int u, v, w;
    	cin >> u >> v >> w;
    	u--, v--;

    	for (int i = 0; i < 30; i++)
    		if ((w >> i) & 1) one[i].unite(u, v);
    		else zero[i].unite(u, v);
    }


    auto choose2 = [](int x) {
    	return (mint(x) * (x - 1)) / 2;
    };

    const mint nc2 = choose2(n);

    vector count(2, vector(30, mint()));
    mint value = 0;

    for (int i = 0; i < 30; i++) {
    	for (int sz: zero[i].sizes())
    		count[0][i] += choose2(sz);
    	for (int sz: one[i].sizes())
    		count[1][i] += choose2(sz);

    	value += (nc2 - count[0][i]) * (1 << i);
    }

    int q; cin >> q;

    while (q--) {
    	int t, x; cin >> t >> x;

    	for (int i = 0; i < 30; i++)
    		value -= (nc2 - count[0][i]) * (1 << i);

    	if (t == 1) {
    		// or
    		for (int i = 0; i < 30; i++)
    			if ((x >> i) & 1)
    				count[1][i] = nc2, count[0][i] = 0;
    	} else if (t == 2) {
    		// and
    		for (int i = 0; i < 30; i++)
    			if (!((x >> i) & 1))
    				count[1][i] = 0, count[0][i] = nc2;
    	} else {
    		// xor
    		for (int i = 0; i < 30; i++)
    			if ((x >> i) & 1)
    				swap(count[1][i], count[0][i]);
    	}

    	for (int i = 0; i < 30; i++)
    		value += (nc2 - count[0][i]) * (1 << i);

    	cout << value << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);


    int T; cin >> T;
    for(int K = 0; K < T; K++)
        darling(K+1);

}