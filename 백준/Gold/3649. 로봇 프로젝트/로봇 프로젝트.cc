#include <bits/stdc++.h>
using namespace std;
#define MAX 10000000
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    int x;
    while (cin >> x)
    {
        int n;
        cin>>n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        int start=0;
        int end=n-1;
        bool check=false;
        while(start<end)
        {
            int sum=v[start]+v[end];
            if(sum==x*MAX)
            {
                cout<<"yes "<<v[start]<<" "<<v[end]<<"\n";
                check=true;
                break;
            }
            if(sum>x*MAX)
                end--;
            else
                start++;
        }
        if(check)
        continue;
        else
        cout<<"danger\n";
    }
}
