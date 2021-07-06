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
ll dist, ind;
 
 
void dfs(ll p, ll i , ll d)
{
   if(d>dist)
   {
      dist=d;
      ind=i;
   }
 
   for(ll j : tree[i])
   {
      if(j!=p)
         dfs(i,j,d+1);
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
 
       
       dfs(-1,0,0);
       dfs(-1,ind,0);
 
       cout<<dist;
      
    }
    return 0;
}
