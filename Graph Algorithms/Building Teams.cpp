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
const int N= 1e5+1;
 
ll n,m, vis[N];
vi adj[N];
 
void solve()
{
	cin>>n>>m;
		for(ll i=1;i<=m;i++)
		{
			ll x,y;
			cin>>x>>y;
			adj[x].pb(y);
			adj[y].pb(x);
		}
 
		for(ll i=1;i<=n;i++)
		{
			if(vis[i]) continue;
 
			queue<ll> q;
			vis[i]=1;
			q.push(i);
 
			while(q.size())
			{
				ll u=q.front(); q.pop();
				for(ll v : adj[u])
				{
					if(vis[u]==vis[v])
					{
						cout<<"IMPOSSIBLE\n";
						return;
					}
					if(vis[v]==3-vis[u]) continue;
					vis[v]=3-vis[u];
					q.push(v);
				}
			}
 
		}
 
		for(ll i=1;i<=n;i++) cout<<vis[i]<<" ";cout<<endl;
}
 
int main()
{
	 FAST_IO;
	 
	 ll test=1;
	// cin>>test;
	 while(test--)
	 {
		solve();
	 }
    return 0;
}
