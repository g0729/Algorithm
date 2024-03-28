#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int groupNum = 1;

    while (1)
    {
        int n;
        cin >> n;
        if (n == 0)
            return 0;

        vector<pair<string, vector<int>>> v;

        for (int i = 0; i < n; i++)
        {
            string name;
            cin >> name;

            vector<int> temp;
            for (int j = 1; j <= n - 1; j++)
            {
                char pn;
                cin >> pn;

                if (pn == 'N')
                    temp.push_back(j);
            }

            v.push_back({name, temp});
        }

        bool check = false;
        cout << "Group " << groupNum << "\n";
        for (int i = 0; i < n; i++)
        {

            if (v[i].second.size() == 0)
                continue;
            else
            {
                check = true;
                for (int j = 0; j < v[i].second.size(); j++)
                {
                    int index = v[i].second[j];

                    index = i - index;

                    if (index < 0)
                    {
                        index += n;
                    }

                    cout << v[index].first << " was nasty about " << v[i].first << "\n";
                }
            }
        }

        if (!check)
            cout << "Nobody was nasty\n";
        cout << endl;
        groupNum++;
    }
}
