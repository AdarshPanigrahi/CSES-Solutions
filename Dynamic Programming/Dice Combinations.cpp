//Adarsh Panigrahi
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define vi vector<int>
#define mi map<int,int>
#define sortv(v) sort(v.begin(),v.end());
#define endl "\n"
#define pb push_back
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
 
const int MOD = 1e9 + 7;
signed main()
{
   FAST_IO;
   
   int test=1;
   //cin>>test;
   while(test--)
   {
    int n;
    cin>>n;
 
    int dp[n+1]={0};
    dp[0]=1;
 
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=min(i,6ll);j++)
      {
        dp[i]+=dp[i-j];
        dp[i]%=MOD;
      }
    }
    cout<<dp[n]<<endl;
   }
    return 0;
}
