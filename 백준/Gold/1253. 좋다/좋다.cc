#include <bits/stdc++.h>
using namespace std;
vector<long long> v;
int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }

    sort(v.begin(),v.end());

    int res=0;

    for (int i = 0; i < n; i++)
    {
        int start=0;
        int end=n-1;
        int now=v[i];
        while(start<end)
        {
            if(start==i)
            start++;
            if(end==i)
            end--;
            long long temp=v[start]+v[end];
            if(start>=end)
            break;
            if(temp==now)
            {
                res++;
                break;
            }
            if(temp>now)
            {
                end--;
            }
            else
            {
                start++;
            }
        }
    }
    
    cout<<res;
}