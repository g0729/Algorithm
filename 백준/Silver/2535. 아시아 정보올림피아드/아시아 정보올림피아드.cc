#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

struct Int3
{
    int a, b, c;
    Int3(int a, int b, int c) : a(a), b(b), c(c) {}
};

bool cmp(Int3 &a, Int3 &b)
{
    return a.c > b.c;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<Int3> v;

    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        Int3 temp(a, b, c);

        v.push_back(temp);
    }

    sort(v.begin(), v.end(),cmp);

    vector<int> cnt(101);

    int check = 0;

    for (int i = 0; check < 3; i++)
    {
        if (cnt[v[i].a] >= 2)
            continue;
        cout << v[i].a << " " << v[i].b << "\n";
        cnt[v[i].a]++;
        check++;
    }

    return 0;
}