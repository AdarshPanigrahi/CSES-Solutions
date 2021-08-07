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
const ll N=1e5+1;
const ll INF = 1e18;
ll n,m;
vector<pair<ll,ll>> adj[N];
vector<ll> dist;
 
void dijk(ll s)
{
	dist.assign(n+1,INF);
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
	dist[s]=0;
	pq.push({0,s});
 
	while(pq.size())
	{
		ll d=pq.top().first;
		ll u=pq.top().second;
		pq.pop();
		if(d > dist[u]) continue;
 
		for( pair<ll,ll> p : adj[u])
		{
			ll v=p.first;
			ll w=p.second;
 
			if(dist[v] > dist[u]+w)
			{
				dist[v]=dist[u]+w;
				pq.push({dist[v],v});
			}
		}
		
	}
}
int main()
{
	 FAST_IO;
	 
	 ll test=1;
	// cin>>test;
	 while(test--)
	 {
		cin>>n>>m;
		for(ll i=0;i<m;i++)
		{
			ll u,v,w;
			cin>>u>>v>>w;
			adj[u].push_back({v,w});
		}
 
		dijk(1);		 
 
		for(ll i=1;i<=n;i++) cout<<dist[i]<<" ";
 
		cout<<endl;	
	 }
    return 0;
}
