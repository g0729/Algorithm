#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(string begin, string target, vector<string> words)
{
    int answer = 0;
    vector<bool> visited(words.size());

    queue<string> q;
    q.push(begin);

    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            string now = q.front();
            q.pop();
            if (now == target)
                return answer;

            for (int i = 0; i < words.size(); i++)
            {
                if (visited[i])
                    continue;
                string next = words[i];

                int cnt = 0;
                for (int j = 0; j < next.length(); j++)
                    if (now[j] != next[j])
                        cnt++;
                if (cnt == 1)
                {
                    visited[i] = true;
                    q.push(next);
                }
            }
        }
        answer++;
    }
    return 0;
}