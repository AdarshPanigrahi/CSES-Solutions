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
       static ll M[1000001];
       memset(M,0,sizeof(M));
 
        ll n;
        cin>>n;
        M[0]=1;
        ll sum=0;
        for(ll i=1;i<=n;i++)
        {
         ll x;
         cin>>x;
         sum+=x;
         for(ll s=100000;s>=x;s--)
         {
            M[s]|= M[s-x];
         }
        }
 
        ll k=0;
 
        for(ll i=1;i<=sum;i++)
        {
         if(M[i]) k++;
        }
 
        cout<<k<<endl;
 
        for(ll i=1;i<=sum;i++)
        {
         if(M[i]) cout<<i<<" ";
         }
         cout<<endl;
     }
    return 0;
}
