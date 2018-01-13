
/**https://www.hackerearth.com/problem/algorithm/shubham-and-tree-1-1f374157/description/**/

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
ll n,l,w,r;
ll a[100005];
ll sum[100005];
vpii v[100005];
set<ll> st[100005];
ll ans[100005];
ll id[100005];
void dfs(int ind,int par)
{
    for(pii i:v[ind])
    {
        if(par==i.F)
        {
            continue;
        }
        sum[i.F]+=sum[ind]+i.S;
        dfs(i.F,ind);
    }
}
void solve(int ind,int par)
{
    //cout<<ind<<",";
    int mx=0,child_id=0;
    for(pii i:v[ind])
    {
        if(par==i.F)
        continue;
        solve(i.F,ind);
        //cout<<i.F<<","<<st[id[i.F]].size()<<endl;
        if(st[id[i.F]].size()>mx)
        {
        	//cout<<"rajat"<<endl;
            mx=st[id[i.F]].size();
            child_id=i.F;
        }
    }
    if(child_id==0)
    {
        id[ind]=ind;
        st[ind].insert(sum[ind]+a[ind]);
        ans[ind]=st[ind].size();
        return ;
    }
    //cout<<"rajat"<<endl;
    id[ind]=id[child_id];
    for(pii i:v[ind])
    {
        if(i.F==par||i.F==child_id)
        {
            continue;
        }
        //cout<<i.F<<endl;
        for(auto itr:st[id[i.F]])
        {
        	//cout<<itr<<",";
            st[id[ind]].insert(itr);
        }
        //cout<<endl<<endl;
    }
    st[id[ind]].insert(a[ind]+sum[ind]);
    ans[ind]=st[id[ind]].size();

}
int main()
{
    fast;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>l>>r>>w;
        v[l].pb({r,w});
        v[r].pb({l,w});
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dfs(1,0);
    solve(1,0);


    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<"\n";
    }
    cout<<endl;
    return 0;
}
}
