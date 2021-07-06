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

vi tree[200001];
ll dist, ind1, ind2;
ll dp1[200001];
ll dp2[200001];
bool vis[200001];

void dfs(ll p, ll i , ll d, ll& ind)
{
   if(d>dist)
   {
      dist=d;
      ind=i;
   }

   for(ll j : tree[i])
   {
      if(j!=p)
         dfs(i,j,d+1,ind);
   }

}


void dfs1(ll i, ll d, bool *vis, ll *dp)
{
   if(!vis[i])
   {
      dp[i]=d;
      vis[i]=1;
   }

   for(ll j : tree[i])
   {
      if(!vis[j])
      {
         dfs1(j,d+1,vis,dp);
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
       ll n;
       cin >> n;
      
       for(ll i=1;i<n;i++)
       {
         ll x,y;
         cin>>x>>y;
         x--; y--;
         tree[x].pb(y);
         tree[y].pb(x);
       }

       
       dfs(-1,0,0,ind1);
       dfs(-1,ind1,0,ind2);

      memset(dp2,0,sizeof(dp2));
      memset(dp1,0,sizeof(dp1));
      memset(vis,0,sizeof(vis));


      dfs1(ind1,0,vis,dp1);
      memset(vis,0,sizeof(vis));
      dfs1(ind2,0,vis,dp2);
    
      for(ll i=0;i<n;i++)
      {
         cout<<max(dp1[i],dp2[i])<<" ";
      }
      
    }
    return 0;
}
