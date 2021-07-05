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
void solve(ll src, vi& ans)
{
   ll subs=0;
   for(ll child : tree[src])
   {
      solve(child,ans);
      subs+= (1 + ans[child]);
    
   }
   ans[src]=subs;
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
 
       vi ans(n+1);
 
       for(ll i=2;i<=n;i++)
       {
         ll x;
         cin>>x;
         tree[x].pb(i);
       }
       solve(1,ans);
 
       for(ll i=1;i<=n;i++)
         cout<<ans[i]<<" ";
      
    }
    return 0;
}
