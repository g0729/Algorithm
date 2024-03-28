#include <bits/stdc++.h>
using namespace std;
int n;
vector<int>v;
bool choose[9];
void dfs()
{
    if(v.size()==n)
    {
        for(int i = 0 ; i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    else
    {
        for(int i =1;i<=n;i++)
        {
            if(!choose[i])
            {
                v.push_back(i);
                choose[i]=true;
                dfs();
                v.pop_back();
                choose[i]=false;
            }
        }
    }
    return ;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin>>n;

    dfs();
}