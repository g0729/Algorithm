#include<bits/stdc++.h>
using namespace std;
long long l,u;
long long cnt[10];
void cal(long long num,long long digit)
{
    while(num>0)
    {
        cnt[num%10]+=digit;
        num /=10;
    }
}
void solution(long long start,long long end,long long digit)
{
    while(start%10!=0&&start<=end)
    {
        cal(start,digit);
        start++;
    }
    if(start>end)
    return;
    while(end%10!=9&&end>=start)
    {
        cal(end,digit);
        end--;
    }
    long long res=(end/10-start/10)+1;
    for(int i = 0 ; i<10;i++)
    {
        cnt[i]+=res*digit;
    }
    solution(start/10,end/10,digit*10);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>l>>u;
    long long res=0;
    if(l==0)
    l=1;
    solution(l,u,1);
    for(int i =1 ; i<10;i++)
    {
        res+=i*cnt[i];
    }
    cout<<res;
}