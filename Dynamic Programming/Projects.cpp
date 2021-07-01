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
struct Job 
{
   ll s, f, p;
};
 
bool cmp(Job a, Job b)
{
   return a.f < b.f ;
}
 
 
ll binarySearch(Job arr[], ll i)
{
   ll lo=0, hi=i-1;
 
   while(lo<=hi)
   {
      ll mid= lo + (hi-lo) / 2;
 
      if(arr[mid].f < arr[i].s)
      {
         if(arr[mid+1].f < arr[i].s)
         {
            lo=mid+1;
         }
         else
         {
            return mid;
         }
      }
      else
      {
         hi=mid-1;
      }
   }
 
   return -1;
}
 
int main()
{
    FAST_IO;
    
    ll test=1;
    //cin>>test;
    while(test--)
    {
         ll n;
         cin >> n;
 
         Job arr[n];
         for(ll i=0;i<n;i++)
         {
            cin>>arr[i].s>>arr[i].f>>arr[i].p;
         }
 
         sort(arr,arr+n,cmp);
 
         vi dp(n,0);
         dp[0]=arr[0].p;
 
         for(ll i=1;i<n;i++)
         {
            ll incl=arr[i].p;
            ll idx=binarySearch(arr,i);
 
            if(idx!=-1)
            {
               incl+=dp[idx];
            }
 
            ll excl=dp[i-1];
 
            dp[i]=max(incl,excl);
 
         }
 
         cout<<dp[n-1];
      
    }
    return 0;
}
