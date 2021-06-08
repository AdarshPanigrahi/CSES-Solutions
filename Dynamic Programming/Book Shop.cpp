//Adarsh Panigrahi
#include <bits/stdc++.h>
using namespace std;
 
#define vi vector<int>
#define mi map<int,int>
#define sortv(v) sort(v.begin(),v.end());
#define endl "\n"
#define pb push_back
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
 
const int MOD = 1e9 + 7;
int dp[1002][100002];
int main()
{
     FAST_IO;
     
     int n,x;
     cin>>n>>x;
     int h[n];
     int s[n];
 
     for(int i=0;i<n;i++)
     {
        cin>>h[i];
     }
 
     for(int i=0;i<n;i++)
     {
        cin>>s[i];
     }
 
     for(int i=0;i<=n;i++)
     {
        for(int j=0;j<=x;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
            else
            {
                if(h[i-1]<=j)
                {
                    dp[i][j]=max(s[i-1]+dp[i-1][j-h[i-1]],dp[i-1][j]);
                }
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
     }
 
     cout<<dp[n][x];
    return 0;
}
