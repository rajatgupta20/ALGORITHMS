#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define ms multiset<ll>
#define vll vector<ll>
#define vii vector<int>
#define pii pair<int,int>
#define vpii vector<pii >
#define pll pair<ll,ll>
#define vpll vector<pll >
#define INF 1000000000
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define F first
#define S second
#define mp make_pair
#define all(v) v.begin(),v.end()
#define pb push_back
#define mod 1000000007
#define maxn 1000000
using namespace std;
int n,l,r;
int level[100005];
vii v[100005];
int dp[100005][21];
void dfs(int ind,int par)
{
    dp[ind][0]=par;
    for(auto i:v[ind])
    {
        if(i==par)
        {
            continue;
        }
        level[i]=level[ind]+1;
        dfs(i,ind);
    }
}
int lca(int u,int v)
{
    if(level[u]<level[v])
    {
        swap(u,v);
    }
    int diff=level[u]-level[v];
    for(int i=0;i<20;i++)
    {
        if(1<<i&diff)
        {
            u=dp[u][i];
        }
    }
    if(u==v)
    return u;
    //cout<<"rajat"<<endl;
    for(int i=20;i>=0;i--)
    {
    	if(dp[u][i]!=-1&&dp[u][i]!=dp[v][i])
    	{
    		u=dp[u][i],v=dp[v][i];
    	}
    }
    return dp[u][0];
}
int main()
{
    fast;
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
    }
    level[1]=1;
    memset(dp,-1,sizeof dp);
    dfs(1,0);

    for(int i=1;i<20;i++)
    {
    	for(int j=1;j<=n;j++)
    	{
    	    int x=dp[j][i-1];
    	    if(x!=-1)
    	    {
    	        dp[j][i]=dp[x][i-1];
    	    }
    	}
    }
    cout<<lca(7,5)<<endl;
    return 0;
}
