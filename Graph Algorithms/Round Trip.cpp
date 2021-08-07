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
 
ll n,m,vis[N],pre[N];
vi adj[N];
 
void dfs(ll u , ll p=0)
{
	vis[u]=1; pre[u]=p;
 
	for(ll v : adj[u])
	{
		if(!vis[v])
		{
			dfs(v,u);
		}
		else
		{
			if(v!=p)
			{
				vi ans;
				ans.pb(v);
				for(ll k=u;k!=v;k=pre[k])
					ans.pb(k);
				ans.pb(v);
				reverse(ans.begin(),ans.end());
 
				cout<<ans.size()<<endl;
				for(ll x: ans) cout<<x<<" ";
					cout<<endl;
				exit(0);
			}
		}
	}
 
}
void solve()
{
	    cin>>n>>m;
	    memset(vis,0,sizeof(vis));
		for(ll i=1;i<=m;i++)
		{
			ll x,y;
			cin>>x>>y;
			adj[x].pb(y);
			adj[y].pb(x);
		}
 
		for(ll i=1;i<=n;i++)
		{
			if(!vis[i]) dfs(i);
		}
 
		cout<<"IMPOSSIBLE\n";
 
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
