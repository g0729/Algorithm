#include <bits/stdc++.h>
using namespace std;
#define MAX 987654321
#define lint long long

bool cmp(int a, int b)
{
    return a>b;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int>v1,v2,v3;
    int n,m,p;
    int sum=0;
    cin>>n>>m>>p;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin>>a;
        sum+=a;
        v1.push_back(a);
    }
    
    for (int i = 0; i < m; i++)
    {
        int a; 
        cin>>a;
        sum+=a;
        v2.push_back(a);
    }
    
    for (int i = 0; i < p; i++)
    {
        int a;
        cin>>a;
        sum+=a;
        v3.push_back(a);
    }
    sort(v1.begin(),v1.end(),cmp);
    sort(v2.begin(),v2.end(),cmp);
    sort(v3.begin(),v3.end(),cmp);

    n=min(n,m);
    n=min(n,p);
    
    int csum=sum;

    for (int i = 0; i < n; i++)
    {
        csum-=v1[i]*(0.1);
        csum-=v2[i]*(0.1);
        csum-=v3[i]*(0.1);
    }
    
    cout<<sum<<endl<<csum;
    return 0;
}
