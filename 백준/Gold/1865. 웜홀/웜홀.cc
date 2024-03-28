#include<bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 501

ll dist[MAX];
int n,m,k;
vector<pair<int,pair<int,int>>>edge;


bool bellman()
{
    for(int i=2;i<=n;i++)
        dist[i]=INF;
    
    for(int i=0;i<n;i++)
    {
        for (int j = 0; j < edge.size(); j++)
        {
            int from=edge[j].first;
            int to=edge[j].second.first;
            int cost=edge[j].second.second;

            if(dist[to]>dist[from]+cost)
            {
                dist[to]=dist[from]+cost;

                if(i==n-1)
                    return false;
            }
        }
    }

    return true;
}
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
int t;
cin>>t;
while(t--)
{
    cin>>n>>m>>k;
    for (int i = 0; i < m; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;

        edge.push_back({a,{b,c}});
        edge.push_back({b,{a,c}});
    }

    for (int i = 0; i < k; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;

        edge.push_back({a,{b,-c}});
    }
    
    if(!bellman())
        cout<<"YES";
    else
        cout<<"NO";
    cout<<"\n";
    edge.clear();
}
return 0;
}