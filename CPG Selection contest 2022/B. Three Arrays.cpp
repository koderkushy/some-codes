#include "bits/stdc++.h"
using namespace std;

#define all(x)              x.begin(), x.end()

template <typename A> istream& operator>> (istream& cin, vector<A> &x){for(int i = 0; i < x.size()-1; i++) cin >> x[i]; return cin >> x[x.size()-1];}
template <typename A, typename B> A amin (A &a, B b){ if (b < a) a = b ; return a; }

using vi = vector<int64_t>;

int64_t solve (int n, vi a, vi b, vi c) {

    assert(n <= 11);

    vector<vector<int>> who(n + 1);

    for (int i = 1; i < (1 << n); i++)
        who[__builtin_popcount(i)].push_back(i);

    const int N = 1 << n;
    const int64_t INF = 1ll << 62;

    vector dp(N, vector(N, INF));
    dp[0][0] = 0;

    for (int pop = 1; pop <= n; pop++)
        for (int x: who[pop]) for (int y: who[pop])
            for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
                if (x & (1 << i) and y & (1 << j))
                    amin(dp[x][y], dp[x^(1<<i)][y^(1<<j)] + a[pop-1] * (b[i] + c[j]) + b[i] * c[j]);

    return dp[N-1][N-1];
}

void darling(int kase){

    int n; cin >> n;
    vi a(n), b(n), c(n);
    cin >> a >> b >> c;

    cout << solve(n, a, b, c) << '\n';


}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);


    int T; cin >> T;
    for(int K = 0; K < T; K++)
        darling(K+1);

}