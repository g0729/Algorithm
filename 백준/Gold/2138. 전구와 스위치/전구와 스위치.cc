#include<iostream>
using namespace std;
char arr[100001];
char brr[100001];
char crr[100001];
int main(){
    long long a,b,ans,minn=99999999;
    cin>>a;
    for(int i=0;i<a;i++)
    {
        cin>>brr[i];
        crr[i]=brr[i];
    }
    for(int i=0;i<a;i++)
    {
        cin>>arr[i];
    }
    crr[0]++;
    crr[1]++;
    if(crr[0]=='2')
    {
        crr[0]='0';
    }
    if(crr[1]=='2')
    {
        crr[1]='0';
    }
    ans=1;
    for(int i=1;i<a;i++)
    {
        if(arr[i-1]!=crr[i-1])
        {
            crr[i-1]++;
            crr[i]++;
            crr[i+1]++;
            if(crr[i-1]=='2')
            {
                crr[i-1]='0';
            }
            if(crr[i]=='2')
            {
                crr[i]='0';
            }
            if(crr[i+1]=='2')
            {
                crr[i+1]='0';
            }
            ans++;
        }
    }
    if(arr[a-1]==crr[a-1])
    {
        minn=min(minn,ans);
    }
    ans=0;
    for(int i=1;i<a;i++)
    {
        if(arr[i-1]!=brr[i-1])
        {
            brr[i-1]++;
            brr[i]++;
            brr[i+1]++;
            if(brr[i-1]=='2')
            {
                brr[i-1]='0';
            }
            if(brr[i]=='2')
            {
                brr[i]='0';
            }
            if(brr[i+1]=='2')
            {
                brr[i+1]='0';
            }
          //  cout<<i;
            ans++;
        }
    }
    //cout<<brr[0]<<arr[0];
    if(arr[a-1]==brr[a-1])
    {
        minn=min(minn,ans);
    }
    if(minn==99999999)
    {
        cout<<-1;
    }
    else
    {
        cout<<minn;
    }
}