#include <bits/stdc++.h>
using namespace std;

int main()
{
    double x1,x2,y1,y2,r1,r2;

    cin>>x1>>y1>>r1>>x2>>y2>>r2;

    double dis=sqrt((double)(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));

    if(dis>=r1+r2)
    cout<<"NO";
    else
    cout<<"YES";
}