#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>flowers;
int main()
{
    int n;
    cin>>n;
    int res=0;
    for (int i = 0; i < n; i++)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        flowers.push_back({100*a+b,c*100+d});
    }
    sort(flowers.begin(),flowers.end());
    int start=301;
    int now=0;
    int max_i=0;
    int max_end=0;
    for(int i =0;i<n;i++)
    {
        if(start>=1201)
        {
            break;
        }

        for(int i = now ; i<flowers.size();i++)
        {
            if(flowers[i].first<=start)
            {
                if(max_end<flowers[i].second)
                {
                    max_end=flowers[i].second;
                    max_i=i;
                }
            }
            else
                break;
        }
        now=max_i;
        start=max_end;
        res++;
    }
    if(start>=1201)
    {
        cout<<res;
    }
    else
    {
        cout<<"0";
    }
}