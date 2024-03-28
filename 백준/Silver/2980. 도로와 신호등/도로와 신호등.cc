#include<bits/stdc++.h>
using namespace std;
vector<tuple<int,int,int>>v;
int n,l;

int main()
{
    cin>>n>>l;
    for(int i = 0 ; i<n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        v.push_back({a,b,c});
    }
    int time=0;
    int now=0;
    
    for(int i = 0 ; i<=l;i++)
    {
        if(i==get<0>(v[now])&&now!=v.size())
        {
            int red=get<1>(v[now]);
            int green=get<2>(v[now]);
            int peroid=red+green;
            if(time%peroid<=red)
            {
                time+=red-time%peroid;
            }
            now+=1;
        }
        time++;
    }
    cout<<time-1;
}