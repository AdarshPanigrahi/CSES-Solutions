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
int dp[1002][1002];
signed main()
{
     FAST_IO;
     
     int n;
     cin>>n;
     char A[n+1][n+1];
     for(int i=1;i<=n;i++)
     {
        for(int j=1;j<=n;j++)
        {
            cin>>A[i][j];
        }
     }
     if(A[n][n]=='*')
     {
        cout<<"0\n";
        return 0;
     }
 
     dp[n][n]=1;
 
     for(int i=n-1;i>=1;i--)
     {
        if(A[i][n]=='*')
        {
            dp[i][n]=0;
        }
        else dp[i][n]=dp[i+1][n];
     }
 
     for(int i=n-1;i>=1;i--)
     {
        if(A[n][i]=='*')
        {
            dp[n][i]=0;
        }
        else dp[n][i]=dp[n][i+1];
     }
 
     for(int i=n-1;i>=1;i--)
     {
        for(int j=n-1;j>=1;j--)
        {
            if(A[i][j]=='*') dp[i][j]=0;
            else
            dp[i][j]=(dp[i][j+1]+dp[i+1][j])%MOD;
        }
     }
 
     cout<<dp[1][1]<<endl;
 
    return 0;
}
