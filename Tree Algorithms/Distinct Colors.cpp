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
 
ll c[200002];
ll res[200001];
vi tree[200002];
set<ll> *st[200001];
 
 
void dfs(ll node, ll par)
{
    ll mx = 0;
    ll mxNode = -1;
    
    for(ll child : tree[node])
    if(child != par)
    {
        dfs(child , node);
        if( st[child]->size() > mx )
        mx = st[child]->size() , mxNode = child;
    }
    
    if(mxNode == -1) st[node] = new set<ll>();
    else             st[node] = st[mxNode];
    
    st[node] -> insert(c[node]);
    
    for(ll child : tree[node])
    if(child != par && child != mxNode)
    {
        for(ll color : *st[child])
        st[node]->insert(color);
    }
    
    res[node] = st[node] -> size();
}
 
int main()
{
     FAST_IO;
     
     ll test=1;
    // cin>>test;
     while(test--)
     {
         ll n,a,b;
         cin>>n;
 
         for(ll i=1;i<=n;i++) cin>>c[i];
 
         for(ll i=1;i<n;i++)
         {
            cin>>a>>b;
            tree[a].pb(b);
            tree[b].pb(a);
         }   
 
         dfs(1,-1);
 
         for(ll i=1;i<=n;i++) cout<<res[i]<<" "; cout<<endl;   
        
     }
    return 0;
}
