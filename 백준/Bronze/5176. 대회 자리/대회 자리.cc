#include<bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long
bool visited[501];
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
int t;
cin>>t;
while(t--)
{
    int n,k;
    cin>>n>>k;
    int res=0;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin>>a;
        if(visited[a])
        res++;
        visited[a]=true;
    }
    

    cout<<res<<"\n";
    memset(visited,false,sizeof(visited));
}
return 0;
}