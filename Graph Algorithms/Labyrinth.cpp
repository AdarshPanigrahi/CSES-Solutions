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
 
const ll MOD = 1e9 + 7;
const ll MAX_N = 1e3 + 1;
 
const ll d = 4;
const ll di[d] = {0, 1, 0, -1};
const ll dj[d] = {1, 0, -1, 0};
const string dc="RDLU";
 
ll n,m;
char A[MAX_N][MAX_N];
ll par[MAX_N][MAX_N];
 
bool isValid(ll i, ll j)
{
    return (0<=i && i<n && 0<=j && j<m && A[i][j]=='.');
}
 
bool isEnd(ll i, ll j)
{
    return (0<=i && i<n && 0<=j && j<m && A[i][j]=='B');
}
 
int main()
{
     FAST_IO;
     
     ll test=1;
//     cin>>test;
     while(test--)
     {
        cin>>n>>m;
        queue<array<ll,2>> q;
 
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++) {
                cin>>A[i][j];
                if(A[i][j]=='A') q.push({i,j});
            }
        }   
      
        while(q.size())
        {
           
            auto[i,j]=q.front();
            q.pop();
 
            for(ll k=0;k<d;k++)
            {
                ll ni= i+di[k];
                ll nj= j+dj[k];
 
                if(isEnd(ni,nj))
                {
                    string ans;
                    par[ni][nj]=k;
 
                    while(A[ni][nj] !='A')
                    {
                        ll p=par[ni][nj];
                        ans+=dc[p];
                        ni -=di[p];
                        nj -=dj[p];
                    }
 
                    reverse(ans.begin(),ans.end());
                    cout<<"YES\n"<<ans.size()<<endl<<ans<<endl;
                    return 0;
                }
                if(isValid(ni,nj))
                {
                    q.push({ni,nj});
                    A[ni][nj]='*';
                    par[ni][nj]=k;
                }
            }
        }
 
        cout<<"NO\n";
 
     }
    return 0;
}
