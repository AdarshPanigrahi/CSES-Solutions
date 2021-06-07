//Adarsh Panigrahi
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define vi vector<int>
#define mi map<int,int>
#define sortv(v) sort(v.begin(),v.end());
#define endl "\n"
#define pb push_back
#define INF 1000000000
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define X    1000000
const int MOD = 1e9 + 7;
int dp[1000002];
int main()
{
   int n;
   cin>>n;
   dp[0]=0;
 
   for(int i=1;i<=n;i++)
   {
     int x=i;
     int mini=INT_MAX;
     while(x)
     {
        int d=x%10;
        if(d!=0)
        {
            mini=min(mini,dp[i-d]);
        }
        x/=10;
     }
     dp[i]=mini+1;
   }
 
   cout<<dp[n]<<endl;
 
   return 0;
}
