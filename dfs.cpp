#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr);
#define int long long
#define endl "\n"
vector<int>a[1000];
int vis[1000];
void dfs(int n)
{
    if(!vis[n])
    {
        vis[n]=1;
        cout<<n<<" ";
        for(auto it:a[n])
        {
            if(!vis[it])
            {
             //   vis[it]=1;
                dfs(it);
            }
        }
    }
}
int32_t main()
{
    fastio
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
    }
    dfs(0);
//    for(int i=0;i<n;i++)     /// to see which nodes are visited
//    {
//        cout<<i<<" ;"<<vis[i]<<endl;
//    }



}
