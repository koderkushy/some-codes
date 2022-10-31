#include "bits/stdc++.h"
using namespace std;

typedef long long           lol;
typedef pair<int,int>       pii;
#define pb                  push_back
#define ub                  upper_bound
#define lb                  lower_bound
#define fo(i,l,r,d)         for(auto i=l; d<0?i>r:(d>0?i<r:0); i+=d)
#define all(x)              x.begin(), x.end()
#define ff                  first
#define ss                  second

mt19937 rng (chrono::high_resolution_clock::now().time_since_epoch().count());
template <typename A, typename B> ostream& operator<< (ostream &cout, pair<A, B> const &p) { return cout << "(" << p.first << ", " << p.second << ")"; }
template <typename A, typename B> istream& operator>> (istream& cin, pair<A, B> &p) {cin >> p.first; return cin >> p.second;}
template <typename A> ostream& operator<< (ostream &cout, vector<A> const &v) {cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";}
template <typename A> istream& operator>> (istream& cin, vector<A> &x){for(int i = 0; i < x.size()-1; i++) cin >> x[i]; return cin >> x[x.size()-1];}
template <typename A, typename B> A amax (A &a, B b){ if (b > a) a = b ; return a; }
template <typename A, typename B> A amin (A &a, B b){ if (b < a) a = b ; return a; }

template<
    int block_size,
    int ind_field_size,
    int block_ptr_size,
    int record_ptr_size
>
struct BPlusTree {
    static constexpr int m_intl = (block_size + ind_field_size) / (ind_field_size + block_ptr_size);
    static constexpr int m_leaf = (block_size - block_ptr_size) / (ind_field_size + record_ptr_size);

    int current_depth{1};

    struct Block {
        const bool is_leaf{};
        vector<int> key{};
        vector<Block*> ptr{};

        pair<int, Block*> insert (const int k, const Block* r) {
            auto j_key = lower_bound(key.begin(), key.end(), k);
            auto j_ptr = ptr.begin() + (j_key - key.begin());

            if (is_leaf) {
                key.insert(j_key, k), ptr.insert(j_ptr, NULL);

                if (key.size() <= m_leaf)
                    return pair(-1, this);

                j_key = key.begin() + key.size() / 2;
                j_ptr = ptr.begin() + key.size() / 2;

                Block* split = new Block {
                    true,
                    vector(j_key, key.end()),
                    vector(j_ptr, ptr.end())
                };

                key.erase(j_key, key.end());
                ptr.erase(j_ptr + 1, ptr.end());

                ptr.back() = split;
                return pair(key.back(), split); 
            }

            auto [split_k, split_b] = (*j_ptr) -> insert(k, r);

            if (split_k == -1)
                return pair(-1, this);

            key.insert(j_key, split_k);
            ptr.insert(j_ptr + 1, split_b);

            if (key.size() <= m_intl)
                return pair(-1, this);

            j_key = key.begin() + key.size() / 2;
            j_ptr = ptr.begin() + key.size() / 2;

            Block* split = new Block {
                false,
                vector(j_key, key.end()),
                vector(j_ptr, ptr.end())
            };

            key.erase(j_key, key.end());
            ptr.erase(j_ptr, ptr.end());

            return pair(key.back(), split);
        }

        auto erase (const int k) {

        }

        void show () {
            if (is_leaf) {
                cout << key << ' ';
                if (ptr.size() and ptr.back() != NULL)
                    ptr.back() -> show();
            }else
                ptr[0] -> show();
        }
    } *root = new Block {true, {}, {}};

    void insert (const int k, const Block* r = NULL) {
        auto [key, b] = root -> insert(k, r);
        if (key != -1) {
            root = new Block {
                false, {key}, {root, b}
            };
            current_depth++;
        }
    }

    void show () {
        root -> show();
        cout << '\n';
    }

};


int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);


    BPlusTree<7, 1, 1, 1> b;

    b.insert(4), b.show();
    b.insert(5), b.show();
    b.insert(7), b.show();
    b.insert(1), b.show();
    b.insert(2), b.show();
    b.insert(3), b.show();
    b.insert(6), b.show();


}
