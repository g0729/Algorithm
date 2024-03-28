#include<bits/stdc++.h>
using namespace std;
vector<string>v;

bool cmp(string a,string b)
{
    return a+b>b+a;
}
int main()
{
    int n,k;
    cin>>k>>n;
    string pick;
    for (int i = 0; i < k; i++)
    {
        string temp;
        cin>>temp;
        if(temp.length()>=pick.length())
        {
            if(temp.length()==pick.length())
            {
                if(stoi(temp)>stoi(pick))
                pick=temp;
            }
            else
            pick=temp;
        }
        v.push_back(temp);
    }
    for (int i = 0; i < n-k; i++)
    {
        v.push_back(pick);
    }
    sort(v.begin(),v.end(),cmp);
    for (int i = 0; i < n; i++)
    {
        cout<<v[i];
    }
       

}