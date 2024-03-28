#include <bits/stdc++.h>
using namespace std;

int main()
{
  char vowel[] = {'a', 'i', 'e', 'o', 'u', 'A', 'I', 'E', 'O', 'U'};

  while (1)
  {
    string s;
    getline(cin, s);
    if (s == "#")
      return 0;
    int res = 0;
    for (int i = 0; i < s.length(); i++)
    {
      for (int j = 0; j < 10; j++)
      {
        if (s[i] == vowel[j])
          res++;
      }
    }

    cout << res << "\n";
  }
}