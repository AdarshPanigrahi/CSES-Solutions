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
const int MAX_N = 1e3 + 1;
 
const int d = 4;
const int di[d] = {0, 1, 0, -1};
const int dj[d] = {1, 0, -1, 0};
 
ll n,m;
char A[MAX_N][MAX_N];
 
bool isValid(ll i, ll j)
{
    return (0<=i && i<n && 0<=j && j<m && A[i][j]=='.');
}
 
void dfs(ll i, ll j)
{
    A[i][j]='#';
    for(ll k=0;k<d;k++)
    {
        ll ni = i + di[k];
        ll nj = j + dj[k];
        if (isValid(ni, nj)) dfs(ni, nj);
    }
}
 
int main()
{
     FAST_IO;
     
     ll test=1;
//     cin>>test;
     while(test--)
     {
        cin>>n>>m;
 
        for(ll i=0;i<n;i++)
            for(ll j=0;j<m;j++) {
                cin>>A[i][j];
        }   
 
        ll ans=0;
        for(ll i=0;i<n;i++)
            for(ll j=0;j<m;j++){
                if(isValid(i,j)){
                    dfs(i,j);
                    ans++;
                }
            }
 
 
        cout<<ans<<endl;    
 
     }
    return 0;
}
