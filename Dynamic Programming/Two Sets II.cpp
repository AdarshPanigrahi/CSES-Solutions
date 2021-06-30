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
   // cin>>test;
    while(test--)
    {
      ll n;
      cin>>n;
 
      ll sum = (n*(n+1))/2;
      if(sum%2)
      {
         cout<<"0";
      }
      else
      {
         sum/=2;
 
          ll dp[n+1][sum+1];
 
         for(ll i=0;i<=sum;i++)
         {
            dp[0][i]=0;
         }
 
         for(ll i=0;i<=n;i++)
         {
            dp[i][0]=1;
         }
 
       
         for(ll i=1;i<=n;i++)
         {
            for(ll j=1;j<=sum;j++)
            {
               if(i<=j)
                 dp[i][j]=(dp[i-1][j]+dp[i-1][j-i])%MOD;
               else dp[i][j]=(dp[i-1][j])%MOD;
              
            }
         }
 
          ll ans= dp[n][sum] * (MOD+1)/ 2 % MOD;
         cout<<ans<<endl;
 
      }
    } 
    return 0;
}
