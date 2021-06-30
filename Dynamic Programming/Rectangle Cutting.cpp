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
        ll n,m;
        cin>>n>>m;
 
        ll dp[n+1][m+1];
 
        for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=m;j++)
            {
               if(i==j)
                dp[i][j]=0;
               else
               {
                 ll ans=LLONG_MAX;
                 for(ll k=1;k<j;k++)
                 {
                    ans=min(ans,1+dp[i][k]+dp[i][j-k]);
                 }
                 for(ll k=1;k<i;k++)
                 {
                    ans=min(ans,1+dp[k][j]+dp[i-k][j]);
                 }
 
                 dp[i][j]=ans;
               }
            }
        }
 
        cout<<dp[n][m];
     }
    return 0;
}
