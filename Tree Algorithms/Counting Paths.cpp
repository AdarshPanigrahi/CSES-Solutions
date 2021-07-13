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
 
void dfs1(ll start, vi* adj , ll parent, ll *value)
{
    for(ll j : adj[start])
    {
        if(j!=parent)
        {
            dfs1(j,adj,start,value);
            value[start]+=value[j];
        }
    }
 
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
 
         for(ll i=2;i<=n;i++)
         {
            ll u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
         }
         dfs(1,0);
         ll value[n+1];
         memset(value,0,sizeof(value));
         while(q--)
         {
            ll u,v;
            cin>>u>>v;
 
            value[u]+=1;
            value[v]+=1;
 
            ll x=lca(u,v);
 
            value[x]-=1;
 
            ll y=par[x][0];
            if(y!=00)
            {
                value[y]-=1;
            }
            
         }
         dfs1(1,adj,0,value);
 
         for(ll i=1;i<=n;i++)
            cout<<value[i]<<" ";
 
          cout<<endl;
     }
    return 0;
}
