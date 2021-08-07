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
#define INF 0x3f3f3f3f3f3f3f3fLL
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
 
const ll MOD = 1e9 + 7;
const ll N=501;
 
ll dist[N][N];
 
int main()
{
     FAST_IO;
     
     ll test=1;
    // cin>>test;
     while(test--)
     {
         ll n,m,q;
         cin>>n>>m>>q;
 
         for(ll i=1;i<=n;i++)
         {
            for(ll j=1;j<=n;j++)
            {
                dist[i][j]= i==j ? 0 :INF;
            }
         }
         for(ll i=0;i<m;i++)
         {
            ll u,v,w;
            cin>>u>>v>>w;
 
            dist[u][v]=dist[v][u]=min(dist[u][v],w);
         }   
 
         for(ll k=1;k<=n;k++)
         {
            for(ll u=1;u<=n;u++)
            {
                for(ll v=1;v<=n;v++)
                {
                    dist[u][v]=min(dist[u][v],dist[u][k] +dist[k][v]);
                }
            }
         }
 
         while(q--)
         {
            ll u,v;
            cin>>u>>v;
 
            cout<<(dist[u][v] == INF ? -1 : dist[u][v])<<endl;
         }
         
     }
    return 0;
}
