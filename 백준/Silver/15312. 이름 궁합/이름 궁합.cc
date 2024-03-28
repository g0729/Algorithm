#include <bits/stdc++.h>
using namespace std;

int alpah[26] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};
int main()
{
    string a, b;
    cin >> a >> b;
    int length = a.length() * 2;
    vector<int> v;
    int j = 0;
    for (int i = 0; i < length; i++)
    {
        if (i % 2 == 0)
        {
            v.push_back(alpah[a[j]-'A']);
        }
        else
        {
            v.push_back(alpah[b[j]-'A']);
            j++;
        }
    }
    vector<int>temp;
    while(1)
    {
        temp.clear();
        for (int i = 0; i < v.size()-1; i++)
        {
            temp.push_back((v[i]+v[i+1])%10);
        }
        if(temp.size()==2)
        {
            cout<<temp[0]<<temp[1];
            break;
        }
        v.clear();
        for (int i = 0; i < temp.size(); i++)
        {
            v.push_back(temp[i]);
        }
        
    }
    
}