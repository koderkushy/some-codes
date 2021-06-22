#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

typedef long long           lol;
#define veci                vector<int> 
#define pii                 pair<int,int>
#define pb                  push_back
#define ub                  upper_bound
#define lb                  lower_bound
#define all(x)              x.begin(),x.end()
#define fo(i,a,n,p)         for(int i=a;(p<0 and i>n) or (p>0 and i<n);i+=p)
#define foin                fo(i,0,n,1)
#define fojn                fo(j,0,n,1)
#define ff                  first
#define ss                  second    
#define cnu                 continue

vector<lol> P;
void iprimes(int N){
    bool ok[N]{false};
    ok[0]=ok[1]=true;
    for(int i=2; i*i<=N; i++){
        if(ok[i]) continue;
        for(int j=i*i; j<N; j+=i) ok[j]=true;
    }
    for(int i=0; i<N; i++) if(!ok[i]) P.push_back(i);
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    lol x,y,k; cin>>x>>y>>k; iprimes(k+1);
    lol an=__gcd(x,y), pr=1e9+7; an%=pr;

    for(lol p: P){
        if(__gcd(x,p)==1 or __gcd(y,p)==1) an*=p, an%=pr;
    }
    cout<<an;

}