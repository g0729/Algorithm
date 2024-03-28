#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int res_arr[3];
    long long res=1e10;
    int n;
    cin>>n;
    vector<long long>v;
    for(int i = 0 ; i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n-2;i++)
    {
        int left=i+1;
        int right=n-1;
        while(left<right)
        {
            long long temp=v[i]+v[left]+v[right];
            if(abs(temp)<res)
            {
                res=abs(temp);
                res_arr[0]=v[i];
                res_arr[1]=v[left];
                res_arr[2]=v[right];
            }
            if(temp<0)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    for(int i = 0 ; i<3;i++)
    {
        cout<<res_arr[i]<<" ";
    }
}