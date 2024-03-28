#include<bits/stdc++.h>
using namespace std;
#define MAX 200000
int n,c;
int house[MAX];
int ans;
int cnt(int dis)
{
    int res=1;
    int now =house[0];
    for(int i =1  ;i<n;i++)
    {
        if(house[i]-now>=dis)
            {
                res++;
                now=house[i];
            }
    }
    return res;
}
void binsearch()
{
    int start = 1;
    int end = house[n-1]-house[0];
    int check;
    while(start<=end)
    {
        int mid=(start+end)/2;
        check=cnt(mid);
        if(check>=c)
        {
            ans=max(ans,mid);
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
}

int main()
{
 cin>>n>>c;
 for (int i = 0; i < n; i++)
 {
     cin>>house[i];
 }
    sort(house,house+n);
    binsearch();
    cout<<ans;
}