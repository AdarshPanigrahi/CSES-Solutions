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
int main()
{
    FAST_IO;
    
    ll test=1;
    //cin>>test;
    while(test--)
    {
       ll n;
       cin >> n;
       ll A[n];
       for(ll i=0;i<n;i++)
       {
         cin>>A[i];
       }
 
     ll dp[n+1];
     for(ll i=1;i<=n;i++)
     {
      dp[i]=LLONG_MAX;
     }
     
     dp[0]=LLONG_MIN;
     for(ll i=0;i<n;i++)
     {
      ll idx=upper_bound(dp,dp+n+1,A[i]) - dp;
      if(A[i] > dp[idx-1] && A[i]<dp[idx])
      {
         dp[idx]=A[i];
      }
     }
 
     ll ans=0;
     for(ll i=n;i>=0;i--)
     {
      if(dp[i]!=LLONG_MAX)
      {
         ans=i;
         break;
      }
     }
 
     cout<<ans;
    }
    return 0;
}
