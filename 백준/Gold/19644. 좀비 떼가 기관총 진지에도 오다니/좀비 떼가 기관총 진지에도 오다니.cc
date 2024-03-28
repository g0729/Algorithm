#include <bits/stdc++.h>
using namespace std;
#define lint long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    lint l, ml, mk, c;

    cin >> l >> ml >> mk >> c;
    bool flag =true;
    queue<int> q;
    for (int i = 1; i <= l; i++)
    {
        lint z;

        cin >> z;

        if(!q.empty())
        {
            if(q.front()+ml-1<i)
            {
                q.pop();
            }
        }
        lint dmg = min(i * mk, mk*ml)-q.size()*mk;

        if(dmg<z)
        {
            q.push(i);
            c--;
            if(c<0)
            {
                flag=false;
            }
        }
    }
    if(flag)
    cout<<"YES";
    else
    cout<<"NO";
}