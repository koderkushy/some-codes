#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

typedef long long           lol;
#define veci                vector<lol> 
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
#define N                   200001

lol p=998244353;

lol bexp(lol a, lol b)
{
    if(a==0 || a==1) return a;
    if(b==0) return 1;
    lol r= bexp(a,b/2);
    if(b & 1) return (((r*r)%p)*a)%p;
    else return (r*r)%p;
}

vector<lol> fac;
void ifac(lol Pr){
    fac.pb(1);
    for(int i=1; i<=N; ++i) 
    {   fac.pb(fac[i-1]*i), 
        fac[i]%=Pr;       }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    ifac(p);

    int n; cin>>n;
    lol a[n]; foin cin>>a[i];

    veci c(31,0);
    foin{
        int x=a[i], j=0;
        while(x){
            if(x&1) c[j]++;
            x/=2, j++;
        }
    }

    lol an=0, e=1; 
    for(int i=0; i<31; i++, e<<=1){
        an+=(((c[i]*(n-c[i]))%p)*e)%p;
        an%=p;
    }
    an*=2, an%=p, an*=fac[n-1], an%=p;
    sort(a,a+n);

    int i=0;
    while(i<n){
        int q=1;
        while(i+q<n and a[i]==a[q+i]) q++;
        an*=bexp(fac[q],p-2), an%=p;
        i+=q;
    }

    cout<<an;
}