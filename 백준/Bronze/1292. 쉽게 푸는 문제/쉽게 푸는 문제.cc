#include<bits/stdc++.h>
using namespace std;
long long sum[1100];
int main()
{
    sum[1]=1;
    int cnt=1;
    int ccnt=1;
    for (int i = 1; i <=1000 ; i++)
    {
        sum[i]=sum[i-1]+ccnt;
        cnt--;
        if(cnt==0)
        {
            ccnt++;
            cnt=ccnt;
        }
    }
    int a,b;
    cin>>a>>b;
    cout<<sum[b]-sum[a-1];
}
