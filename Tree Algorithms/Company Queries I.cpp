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
 
ll n, q, par[MAX_N][MAX_L];
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
            dfs(j,i);
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
 
         for(ll v=2;v<=n;v++)
         {
            ll u;
            cin>>u;
            adj[u].pb(v);
         }
         dfs(1,0);
         while(q--)
         {
            ll x,k;
            cin>>x>>k;
            for(ll i=0;i<MAX_L;i++)
            {
                if(k & (1<<i))
                    x=par[x][i];
 
            }
 
            if(x>0) cout<<x<<endl;
            else cout<<"-1\n";
         }
        
     }
    return 0;
}
