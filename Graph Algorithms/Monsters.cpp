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
const ll N= 1e3 + 1;
 
const ll d=4;
const ll di[d] = {0, 1, 0, -1};
const ll dj[d] = {1, 0, -1, 0};
const string dc = "RDLU";
 
ll n, m, pre[N][N];
char graph[N][N];
 
bool isOk(ll i, ll j) {
	return 0 <= i && i < n && 0 <= j && j < m && graph[i][j] == '.';
}
 
bool isEnd(ll i, ll j) {
	return (i == 0 || i == n - 1 || j == 0 || j == m - 1) && graph[i][j] == 'A';
}
 
pair<ll,ll> A;
 
 
void solve()
{
	cin>>n>>m;
	queue<pair<ll,ll>> q;
 
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<m;j++)
		{
			cin>>graph[i][j];
			if(graph[i][j]=='M') q.push({i,j});
			if(graph[i][j]=='A') A={i,j};
		}
	}
 
	if(isEnd(A.first,A.second))
	{
		cout<<"YES\n0\n";
		return;
	}
 
	q.push(A);
 
	while(q.size())
	{
		ll i=q.front().first;
		ll j=q.front().second;
		q.pop();
 
		for(ll k=0;k<d;k++)
		{
			ll ni=i+di[k];
			ll nj=j+dj[k];
 
			if(isOk(ni,nj))
			{
				graph[ni][nj]=graph[i][j];
				pre[ni][nj]=k;
				q.push({ni,nj});
			}
 
			if(isEnd(ni,nj))
			{
				pre[ni][nj]=k;
				string ans;
 
				while(ni!=A.first || nj!=A.second)
				{
					ll p=pre[ni][nj];
					ni-=di[p];
					nj-=dj[p];
					ans+=dc[p];
				}
 
				reverse(ans.begin(),ans.end());
				cout<<"YES\n"<<ans.length()<<endl<<ans<<endl;
				return;
			}
		}
	}
 
	cout<<"NO\n";
}
int main()
{
	 FAST_IO;
	 
	 ll test=1;
	 //cin>>test;
	 while(test--)
	 {
		solve();
	 }
    return 0;
}
