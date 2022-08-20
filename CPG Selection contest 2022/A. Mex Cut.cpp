#include "bits/stdc++.h"

using namespace std;

#define all(x)              x.begin(), x.end()

template <typename A> istream& operator>> (istream& cin, vector<A> &x){for(int i = 0; i < x.size()-1; i++) cin >> x[i]; return cin >> x[x.size()-1];}
template <typename A, typename B> A amin (A &a, B b){ if (b < a) a = b ; return a; }


void darling(int kase){

    int n; cin >> n;
    vector a(n, 0);
    cin >> a;

    vector count(n+1, 0);
    for (int x: a)
    	count[min(x, n)]++;

    bool can_zero = 0;
    int ans = 1 << 30;

    for (int i = 0; i < n; i++) {
    	amin(ans, count[i] + i);
    }

    for (int i = 1; i <= n; i++) {
    	if (count[i] and count[i] + i > ans)
    		can_zero = 1;
    }

    cout << ans + can_zero << '\n';
    
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    int T; cin >> T;
    for(int K = 0; K < T; K++)
        darling(K+1);

}

