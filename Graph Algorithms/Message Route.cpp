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
const int N = 1e5 + 1;
 
ll n, m, dist[N], pre[N];
vi adj[N];
 
int main()
{
     FAST_IO;
     
     ll test=1;
     //cin>>test;
     while(test--)
     {
         cin>>n>>m;
 
         for(ll i=0;i<m;i++)
         {
            ll x,y;
            cin>>x>>y;
 
            adj[x].pb(y);
            adj[y].pb(x);
         }
 
         memset(dist,0x3f,sizeof(dist));
         queue<ll> q;
         q.push(1);
         dist[1]=1;
         pre[1]=0;
 
         while(q.size())
         {
            ll u=q.front();
             q.pop();
 
            for(ll v: adj[u])
            {
                if(dist[v] > dist[u]+1)
                {
                    dist[v]=dist[u]+1;
                    pre[v]=u;
                    q.push(v);
                }
            } 
         }
 
         if(dist[n] < 1e9)
         {
            cout<<dist[n]<<endl;
            vi ans;
            ll u=n;
            while(u)
            {
                ans.pb(u);
                u=pre[u];
            }
 
            reverse(ans.begin(),ans.end());
 
            for(ll x : ans) cout<<x<<" "; cout<<endl;
         }
         else
            cout<<"IMPOSSIBLE\n";
 
        
     }
    return 0;
}
