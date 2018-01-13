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
vii v[100005],sum[100005];
int a[100005],par[100005],p[100005],level[100005];
bool check[100005],visited[100005];
vii ans;
void dfs(int ind)
{
    visited[ind]=true;
    ans.pb(ind);
    for(auto itr:v[ind])
    {
        if(!visited[itr])
        {
            level[itr]=level[ind]+1;
            par[itr]=ind;
            dfs(itr);
        }
    }
    ans.pb(ind);
}
void pre(int ind,int head,int pre_sec)
{
    int cur_sec=sqrt(level[ind])+1;
    if(cur_sec==1)
    {
        p[ind]=1;
    }
    else
    {
        if(cur_sec==pre_sec+1)
        {
            p[ind]=par[ind];
            head=ind;
        }
        else
        {
            p[ind]=par[head];
        }
    }
    for(auto itr:v[ind])
    {
        if(itr!=par[ind])
        {
            pre(itr,head,cur_sec);
        }
    }
}
int lca(int u , int v){
    while(p[u] != p[v]){
        if(level[u] > level[v]){
            u = p[u];
        }
        else{
            v = p[v];
        }
    }
    while(u != v){
        if(level[u] > level[v]){
            u = par[u] ;
        }
        else{
            v = par[v] ;
        }
    }
    return u ; //Either u or v store the lca.
}
int main()
{
    ans.pb(0);
    int q;
    scanf("%d%d",&n,&q);
    int cc;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n-1;i++)
    {
        scanf("%d%d",&l,&r);
        v[l].pb(r);
        v[r].pb(l);
    }
    par[1]=1;
    level[1]=0;
    dfs(1);
    for(int i=1;i<ans.size();i++)
    {
        sum[ans[i]].pb(i);
    }
    int lc=lca(1,3); ///find lca of any two nodes
    cout<<lc<<endl;
    return 0;
}
