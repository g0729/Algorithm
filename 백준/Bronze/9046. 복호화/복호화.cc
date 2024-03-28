#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    cin.ignore();

    while (n--)
    {
        string s;
        getline(cin, s);

        vector<int> alpha(26);

        for (int i = 0; i < s.length(); i++)
        {
            if (isalpha(s[i]))
            {
                alpha[s[i] - 'a']++;
            }
        }

        int res=*max_element(alpha.begin(),alpha.end());
        int idx=max_element(alpha.begin(),alpha.end())-alpha.begin();
        int cnt=0;

        char temp=idx+'a';
        for (int i = 0; i < 26; i++)
        {
            if(alpha[i]==res)
                cnt++;
        }
        
        if(cnt>=2)
            cout<<"?";
        else
            cout<<temp;

        cout<<"\n";
        
    }
    return 0;
}