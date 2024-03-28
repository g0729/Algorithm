#include <bits/stdc++.h>
using namespace std;

struct Tint
{
    int a, b, c;
    Tint(int a, int b,int c)
    {
       this-> a=a;
        this->b=b;
        this->c=c;
    }
};
 bool cmp(Tint a, Tint b)
{
    if (a.a == b.a)
        return a.b < b.b;
    return a.a < b.a;
}
bool cmp2(Tint a,Tint b)
{
    return a.b<b.b;
}
int main()
{
    int n;
    cin >> n;

    vector<Tint>v;

    for(int i  = 0 ; i<n;i++)
    {
        int a;
        cin>>a;
        Tint temp(a,i,0);
        v.push_back(temp); 
    }
    sort(v.begin(),v.end(),cmp);

    for(int i = 0 ; i<n;i++)
    {
        v[i].c=i;
    }
    
    sort(v.begin(),v.end(),cmp2);

    for(int i = 0 ; i<n;i++)
    {
        cout<<v[i].c<<" ";
    }
}