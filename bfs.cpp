#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr);
#define int long long
#define endl "\n"
vector<int>a[1000];
int vis[1000];
void bfs(queue<int>q)
{
    while(q.size())
    {
        int p=q.front();
        q.pop();
        cout<<p<<" ";
        for(int i=0;i<a[p].size();i++)
        {
            if(!vis[a[p][i]])
            {
                 q.push(a[p][i]);
                vis[a[p][i]]=1;

            }
        }
//        for(auto it:a[p])
//        {
//            if(!vis[it])
//            {
//                vis[it]=1;
//                q.push(it);
//                bfs(it);
//            }
//        }
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
    queue<int>q;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            q.push(i);
            vis[i]=1;
            bfs(q);

        }
    }


}
