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
const int MAX_N = 2e5 + 1;
const int MAX_L = 20;
 
ll n, q, par[MAX_N][MAX_L], dep[MAX_N];
vi adj[MAX_N];
 
void dfs(ll i, ll p)
{
    par[i][0]=p;
    for(ll j=1;j<MAX_L;j++)
    {
        par[i][j]=par[par[i][j-1]][j-1];
    }
 
    for(ll j : adj[i])
    {
        if(j!=p)
        {
            dep[j]=dep[i]+1;
            dfs(j,i);
        }
    }
}
 
ll ancestor(ll u, ll k) {
    for (ll i = 0; i < MAX_L; i++) 
        if (k & (1 << i)) 
            u = par[u][i];
    return u;
}
 
ll lca(ll u, ll v)
{
    if(dep[u]<dep[v]) swap(u,v);
    u=ancestor(u,dep[u]-dep[v]);
 
    if(u==v) return u;
 
    for(ll i=MAX_L-1;i>=0;i--)
    {
        if(par[u][i]!=par[v][i])
        {   
            u=par[u][i],v=par[v][i];
        }
    }
 
    return par[u][0];
}
int main()
{
     FAST_IO;
     
     ll test=1;
     //cin>>test;
     while(test--)
     {
         ll n,q;
         cin>>n>>q;
 
         for(ll v=2;v<=n;v++)
         {
            ll u;
            cin>>u;
            adj[u].pb(v);
         }
         dfs(1,0);
         while(q--)
         {
            ll u,v;
            cin>>u>>v;
            cout<<lca(u,v)<<endl;
         }
        
     }
    return 0;
}
