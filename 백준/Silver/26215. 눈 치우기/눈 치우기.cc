#include<bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
vector<int>v;

int n;
cin>>n;

int res=0;

for (int i = 0; i < n; i++)
{
    int a;
    cin>>a;
    v.push_back(a);
}

while(1)
{
    sort(v.begin(),v.end(),greater<int>());
    
    if(v[0]==0)
    break;

    v[0]--;
    if(v[1]>0)
    v[1]--;

    res++;
}
if(res>1440)
cout<<"-1";
else
cout<<res;
return 0;
}