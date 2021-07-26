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
 
vi adj[N];
ll n,m;
bool vis[N];
 
void dfs(ll i)
{
    vis[i]=1;
    for(ll j: adj[i])
    {
        if(!vis[j]) dfs(j);
    }
}
int main()
{
     FAST_IO;
     
     ll test=1;
   //  cin>>test;
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
 
        vi v;
        for(ll i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                dfs(i);
                v.pb(i);
            }
        }
 
        cout<<v.size()-1<<endl;
 
        for(ll i=1;i< v.size();i++)
            cout<<v[i-1]<<" "<<v[i]<<endl;
        
     }
    return 0;
}
