#include<bits/stdc++.h>
using namespace std;
#define MAX 500001
int top[MAX];
int bottom[MAX];
int main()
{
    int n,h;
    cin>>n>>h;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin>>a;
        if(i%2==0)  
        {
            bottom[a]++;
        }
        else
        {
            top[h-a+1]++;
        }
    }
    for (int i = 2; i <= h; i++)
    {
        top[i]+=top[i-1];
    }
    for (int i =h-1; i >0; i--)
    {
        bottom[i]+=bottom[i+1];
    }
    int min,min_i;
    min=200001;
    for (int i = 1; i <= h; i++)
    {
        if(bottom[i]+top[i]<min)
        {
            min=bottom[i]+top[i];
        }
    }
    int cnt=0;
    for (int i = 1; i <= h; i++)
    {
        if(bottom[i]+top[i]==min)
        cnt++;
    }
    cout<<min<<" "<<cnt;
    

}