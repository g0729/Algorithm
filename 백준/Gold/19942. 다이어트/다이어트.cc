#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

struct food
{
    int protein, fat, carbon, vita, price;
    food(){};
    food(int a, int b, int c, int d, int e)
    {
        protein = a;
        fat = b;
        carbon = c;
        vita = d;
        price = e;
    };
};
vector<food> v;
vector<int> resIdx;
bool check[15];
int n;
food target;
int res = 1e9;
void dfs(int now, food temp)
{
    if (now == n)
    {
        if (temp.protein >= target.protein && temp.fat >= target.fat && temp.carbon >= target.carbon && temp.vita >= target.vita)
        {
            vector<int> tempIdx;
            if (res > temp.price)
            {
                res = temp.price;
                for (int i = 0; i < n; i++)
                {
                    if (check[i])
                        tempIdx.push_back(i + 1);
                }
                resIdx = tempIdx;
            }
            else if (res == temp.price)
            {
                for (int i = 0; i < n; i++)
                {
                    if (check[i])
                        tempIdx.push_back(i + 1);
                }

                string a, b;

                for (int i = 0; i < tempIdx.size(); i++)
                {
                    if (tempIdx[i] >= 10)
                        a.push_back((char)(55 + tempIdx[i]));
                    else
                        a.push_back(tempIdx[i] + '0');
                }
                for (int i = 0; i < resIdx.size(); i++)
                {
                    if (resIdx[i] >= 10)
                        b.push_back((char)(55 + resIdx[i]));
                    else
                        b.push_back(resIdx[i] + '0');
                }

                if(a<b)
                    resIdx=tempIdx;
            }
        }
        return;
    }

    food temp2 = v[now];
    temp2.protein += temp.protein;
    temp2.fat += temp.fat;
    temp2.carbon += temp.carbon;
    temp2.vita += temp.vita;
    temp2.price += temp.price;

    dfs(now + 1, temp);
    check[now] = true;
    dfs(now + 1, temp2);
    check[now] = false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    int a, b, c, d, e;
    cin >> a >> b >> c >> d;

    target = food(a, b, c, d, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c >> d >> e;
        v.push_back(food(a, b, c, d, e));
    }

    dfs(0, food(0, 0, 0, 0, 0));

    if (res == 1e9)
    {
        cout << "-1";
        return 0;
    }
    cout << res << "\n";

    for (int i = 0; i < resIdx.size(); i++)
    {
        cout << resIdx[i] << " ";
    }

    return 0;
}