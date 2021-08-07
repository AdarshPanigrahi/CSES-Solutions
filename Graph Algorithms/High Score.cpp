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
const int N = 2.5e3 + 1;
const ll INF = 1e17;
const ll NINF = INF*(-1);
 
ll n,m, vis[N];
vector<array<ll,2>> adj[N];
vector<ll> dist;
 
int main()
{
     FAST_IO;
     
     ll test=1;
    // cin>>test;
     while(test--)
     {
        cin>>n>>m;
        for(ll i=0;i<m;i++)
        {
            ll u,v,w;
            cin>>u>>v>>w;
            adj[u].pb({v,-1*w});
        } 
 
        dist.assign(n+1,INF);
        dist[1]=0;
 
        for (int k = 0; k < n ; k++)  {
        for (int u = 1; u <= n; u++){
            for (auto [v, w] : adj[u]) {
 
                if(dist[u]==INF) continue;
                dist[v] = min(dist[v], dist[u] + w);
               // dist[v]=max(dist[v],NINF);
           }
        }
      }
 
 
         for (int k = 0; k < n ; k++)  {
        for (int u = 1; u <= n; u++){
            for (auto [v, w] : adj[u]) {
 
                if(dist[u]==INF) continue;
                dist[v]=max(dist[v],NINF);
                if(dist[u]+w < dist[v])
                {
                    dist[v]=NINF;
                }
           }
        }
      }
 
 
      if(dist[n]==NINF) cout<<"-1\n";
      else cout<<-dist[n]<<endl;
 
     }
    return 0;
}
