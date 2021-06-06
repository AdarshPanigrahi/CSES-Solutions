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
 
int main()
{
    static int dp[X + 1];
    int n, x;
    
   cin>>n>>x;
    dp[0] = 1;
    for(int i=0;i<n;i++){
      int c;
       cin>>c;
        for (int j = c; j <= x; j++)
            dp[j] = (dp[j] + dp[j - c]) % MOD;
    }
   cout<<dp[x];
    return 0;
}
