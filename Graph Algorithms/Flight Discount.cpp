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
 
const ll MOD = 1e9 + 7;
const ll N = 1e5 +2;
const ll INF = 1e18;
 
 
ll n,m;
vector<array<ll,2>> adj[2][N];
vector<ll> dist[2];
 
 
void dijk(ll t, ll s)
{
    dist[t].assign(n+1,INF);
    priority_queue<array<ll,2>,vector<array<ll,2>>,greater<array<ll,2>>> pq;
    dist[t][s]=0; pq.push({0,s});
 
    while(pq.size()){
        auto [d,u]= pq.top(); pq.pop();
        if(d > dist[t][u]) continue;
        for(auto [v,w] : adj[t][u]){
            if(dist[t][v] > dist[t][u] + w){
                dist[t][v]=dist[t][u]+w;
                pq.push({dist[t][v],v});
            }
        }
    }
}
 
 
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
            adj[0][u].pb({v,w});
            adj[1][v].pb({u,w});
         }
 
         dijk(0,1);
         dijk(1,n);
 
         ll ans=INF;
 
         for(ll u=1;u<=n;u++){
            for(auto [v,w]: adj[0][u]){
                ans=min(ans,dist[0][u] + dist[1][v] + w/2);
            }
         }
 
         cout<<ans<<endl;
 
     }
    return 0;
}
