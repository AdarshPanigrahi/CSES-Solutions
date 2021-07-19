//Adarsh Panigrahi
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define vi vector<ll>
#define mi map<ll,ll>
#define pi pair<ll,ll>
#define sortv(v) sort(v.begin(),v.end());
#define endl "\n"
#define pb push_back
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
 
const int MOD = 1e9 + 7;
const ll N = 200001;
 
vi tree[N];
ll temp[N];
ll timer = 0;
 
void dfs(ll node, ll par , ll *s, ll *in, ll *out)
{
    s[timer]=temp[node];
    in[node] = ++timer;
 
    for(ll child : tree[node])
    if(child != par)
    dfs(child , node,s,in,out);
 
    s[timer]=-temp[node];
    out[node]=++timer;
}
 
void build( ll arr[], ll n, ll *st)
{
    for (ll i=0; i<n; i++)   
        st[n+i] = arr[i];
     
    for (ll i = n-1; i > 0; --i)    
        st[i] = st[i<<1] + st[i<<1 | 1];   
}
 
void update(ll p, ll value, ll n, ll *st)
{
    st[p+n] = value;
    p = p+n;
   
    for (ll i=p; i > 1; i >>= 1)
        st[i>>1] = st[i] + st[i^1];
}
 
ll sum(ll l, ll r, ll n, ll *st)
{
    ll res = 0;
   
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l&1)
            res += st[l++];
     
        if (r&1)
            res += st[--r];
    }
     
    return res;
}
 
int main()
{
     FAST_IO;
     
     ll test=1;
    // cin>>test;
     while(test--)
     {
        ll n , q , a , b , code;
        cin>>n>>q;
 
        for(ll i=1;i<=n;i++) cin>>temp[i];
        for(ll i=1;i<=n-1;i++) cin>>a>>b , tree[a].pb(b) , tree[b].pb(a);
 
         ll st[4*n];
         ll s[2*n];
 
         ll out[n+1];
         ll in[n+1];
 
         dfs(1,-1,s,in,out);
         build(s,2*n,st);
 
        while(q--)
       {
        cin>>code;
        
        if(code == 1) {
            cin>>a>>b;
 
            update(in[a]-1,b,2*n,st);
            update(out[a]-1,-b,2*n,st);
        }
        else{
            cin>>a;
            cout<<sum(0,in[a],2*n,st)<<endl;
        }
       }
 
     }
    return 0;
}
