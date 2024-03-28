#include<bits/stdc++.h>
using namespace std;
#define MAX 64
int MAP[MAX][MAX];
int n;

void dfs(int x,int y,int size)
{
    bool zero,one;
    zero=one=true;
    for (int i = x; i < x+size; i++)
    {
        for (int q = y; q < y+size; q++)
        {
            if(MAP[i][q]==1)
            zero=false;
            if(MAP[i][q]==0)
            one=false;
            if(!one&&!zero)
            break;
        }
    }
    if(zero)
    {
        cout<<0;
        return;
    }
    if(one)
    {
        cout<<1;
        return;
    }
    cout<<"(";
    dfs(x,y,size/2);
    dfs(x,y+size/2,size/2);
    dfs(x+size/2,y,size/2);
    dfs(x+size/2,y+size/2,size/2);
    cout<<")";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin>>s;
        for (int q = 0; q < n; q++)
        {
            MAP[i][q]=s[q]-'0';
        }
    }
    dfs(0,0,n);
}