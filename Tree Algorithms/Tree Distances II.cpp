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
 
vector<int> tree[200001];
ll ds[200001], sk[200001], n;
 
 
void fill(ll i , ll par)
{
    sk[i]=1;
    for(ll j : tree[i])
    {
        if(j!=par)
        {
            fill(j,i);
            sk[i]+=sk[j];
            ds[i]+=ds[j]+sk[j];
        }
    }
}
 
void dfs(ll i, ll par, ll d)
{
    ds[i]=d;
 
    for(ll j : tree[i])
    {
        if(j!=par)
            dfs(j,i,ds[i]-sk[j]+n-sk[j]);
    }
}
 
int main()
{
     FAST_IO;
     
     ll test=1;
    // cin>>test;
     while(test--)
     {
         cin >> n;
        for(ll i=1;i<n;i++)
        {
            ll a,b;
            cin>>a>>b;
            a--,b--;
 
            tree[a].pb(b);
            tree[b].pb(a);
        }
 
 
        fill(0,-1);
        dfs(0,-1,ds[0]);
 
        for(ll i=0;i<n;i++)
        {
            cout<<ds[i]<<" ";
        }
        cout<<endl;
 
     }
    return 0;
}
