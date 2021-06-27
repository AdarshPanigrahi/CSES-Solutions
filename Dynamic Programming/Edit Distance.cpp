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
        string s,t;
        cin>>s>>t;
       
        int n=s.length();
        int m=t.length();
        int i,j;
        int dp[n+1][m+1];
        for (i = 0; i <= n; i++)
        dp[i][0] = i;
    for (j = 0; j <= m; j++)
        dp[0][j] = j;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
      cout<<dp[n][m]<<endl;
     }
    return 0;
}
