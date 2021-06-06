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
 
const int MOD = 1e9 + 7;
int c[101];
int dp[1000001];
int main()
{
    int n,x;
    cin>>n>>x;
    for(int i=0;i<n;i++) 
        cin>>c[i];
    
    dp[0]=0;
 
    for(int i=1;i<=x;i++)
      dp[i]=INF;
 
    for(int i=1;i<=x;i++)
    {
    
      for(int j=0;j<n;j++)
      {
        if(i-c[j] >= 0)
        {
          dp[i]=min(dp[i], dp[ i-c[j] ]+1);
        }
        
      }
    } 
 
    if(dp[x]==INF) dp[x]=-1;
 
    cout<<dp[x];
}
