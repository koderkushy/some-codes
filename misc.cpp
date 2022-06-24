#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#include <ext/rope>
using namespace __gnu_cxx;

typedef long long       lol;
typedef pair<int,int>   pii;

const double PI = 3.141592653589793;

#define all(x)              x.begin(), x.end()
#define ff                  first
#define ss                  second
#define pb                  push_back

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.first << ", " << p.second << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) {cin >> p.first; return cin >> p.second;}
template<typename A> istream& operator>>(istream& cin, vector<A> &x){for(int i = 0; i < x.size()-1; i++) cin >> x[i]; return cin >> x[x.size()-1];}

int main(){

    lol a = rng();
    cout<< a;
    return 0;
}

// Hilbert curve mapping from 2d to 1d:

lol hilbertorder(int x, int y){
    lol o = 0; const int mx = 1<<19;
    for(int p = mx; p; p >>= 1){
        bool a = x&p, b = y&p;
        o = (o << 2) | (a * 3) ^ static_cast<int>(b);
        if(!b){
            if(a) x = mx - x, y = mx - y;
            x ^= y ^= x ^= y;
        }
    }
    return o;
}

// LIS of a vector:

int LIS(vector<int> a){
    int n = a.size();
    set<int> every; map<int, int> val; int c = 1;
    for(auto x: a) every.insert(x);
    for(auto x: every) val[x] = c++;

    vector<int> b(n, 0);
    for(int i = 0; i < n; i++)
        b[i] = val[a[i]];

    vector<int> f(c, 0);
    auto ins = [&](int i, int x){ while(i < c) f[i] = max(f[i], x), i += i&(-i); return x; };
    auto ask = [&](int i){ int mx = 0; while(i) mx = max(mx, f[i]), i -= i&(-i); return mx; };

    int lis = 0;
    for(int i = 0; i < n; i++)
        lis = max(ins(b[i], ask(b[i])+1), lis);
    return lis;
}

// custom integer hash:

struct chash {
    size_t operator()(uint64_t x) const {
        // http://xorshift.di.unimi.it/splitmix64.c
        static const uint64_t FIXED_RNDM = chrono::steady_clock::now().time_since_epoch().count();
        x += FIXED_RNDM, x += 0x963779c97f4aac15;
        x = (x ^ (x >> 30)) * 0xbf58476d2ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d149bb133111ab;
        return x ^ (x >> 31);
    }
};

// fft modulos:

struct FFT_mods { int MOD, rt, it, pw; } 
fft_mods[5] = {
    { 7340033, 5, 4404020, 1 << 20 },
    { 415236097, 73362476, 247718523, 1<<22 },
    { 463470593, 428228038, 182429, 1<<21},
    { 998244353, 15311432, 469870224, 1 << 23 },
    { 918552577, 86995699, 324602258, 1 << 22 }
};

// walk on fenwick tree

int walk(int sum, int MX){
    int i = 0, p = 0;
    for(; MX; MX >>= 1)
        if(MX + i <= n and f[MX + i] + p < sum)
            p += f[i += MX];
    return i+1;
}