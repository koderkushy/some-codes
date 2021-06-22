#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; 

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long           lol;
#define veci                vector<int> 
#define vecp                vector<pair<int,int>> 
#define pb                  push_back
#define ub                  upper_bound
#define lb                  lower_bound
#define bs                  binary_search
#define all(x)              x.begin(), x.end()
#define fo(i,a,n,p)         for (int i=a; (p<0 and i>n) or (p>0 and i<n) ; i+=p)
#define foin                fo(i,0,n,1)
#define ff                  first
#define ss                  second    
#define cnu                 continue
#define oset 				tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define N					100001

lol t=998244353;


lol bexp(lol a, lol b=t-2, lol Pr=t)
{
    if(a==0 || a==1) return a;
    if(b==0) return 1;
    lol r= bexp(a,b/2,Pr);
    if(b & 1) return (((r*r)%Pr)*a)%Pr;
    else return (r*r)%Pr;
}	


int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);      

    int m, n; cin>>m>>n;
    lol b[m], a[n]{0}; fo(i,0,m,1) cin>>b[i];
    lol w[m+1]{0}; w[0]=1;
    
    lol q[m]{0}; 
    fo(i,0,m,1){
    	lol s=0;
    	fo(j,i,m,1) s+=b[j], s%=t, q[i]+=s, q[i]%=t;
    }
    vector<lol> bex(m+2);
    fo(i,1,m+2,1) bex[i]=bexp(i);

    foin{
    	fo(j,0,m,1) {
    		a[i]+=((q[j]*w[j])%t)*bex[m+1-j], a[i]%=t;
    		
    	}
    	lol e=0;
    	fo(j,0,m,1){
    		e+=w[j]*bex[m+1-j], e%=t;
    		w[j]=e;
    	}

    }

    foin cout<<a[i]<<' '; 


}