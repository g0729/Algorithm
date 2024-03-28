#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h,m,s;
    int ps;
    cin>>h>>m>>s>>ps;
    int total;
    total=60*60*h+60*m+s;
    total+=ps;
    total=total%(60*60*24);
    cout<<total/(60*60)<<" "<<(total%(60*60))/60<<" "<<total%60;

}