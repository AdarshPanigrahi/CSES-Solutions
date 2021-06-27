//Adarsh Panigrahi
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define vi vector<int>
#define mi map<int,int>
#define pi pair<int,int>
#define sortv(v) sort(v.begin(),v.end());
#define endl "\n"
#define pb push_back
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
 
const int MOD = 1e9 + 7;
int main()
{
     FAST_IO;
 
     int n,m;
     cin>>n>>m;
     int a[n];
     int dp[n+2][m+2];
     memset(dp,0,sizeof(dp));
     for(int i=0;i<n;i++)
     {
        cin>>a[i];
     }
 
     for(int i=1;i<=m;i++)
     {
       if(a[0]==0 || a[0] ==i)
       {
        dp[1][i]=1;
       }
       else
        dp[1][i]=0;
     }
 
     for(int i=2;i<=n;i++)
     {
        for(int j=1;j<=m;j++)
        {
            if(a[i-1]==0 || a[i-1]==j)
            {
                dp[i][j]=((dp[i-1][j-1]+dp[i-1][j])%MOD + (dp[i-1][j+1]))%MOD;
            }
            else
                dp[i][j]=0;
        }
     }
     int ans=0;
     for(int i=1;i<=m;i++)
     {
        ans= (ans+ dp[n][i])%MOD;
     }
 
     cout<<ans<<endl;
    return 0;
}
