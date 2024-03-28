#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
#define setting cin.tie(0)->sync_with_stdio(0)
using namespace std;


int main(){
  setting;

  int tc;
  cin >> tc;

  while(tc--){
    int l;
    cin >> l;

    int tx, ty;
    cin >> tx >> ty;
    int x, y;
    cin >> x >> y;

    queue<pair<int, pair<int, int>>> q;

    q.push({0, {tx, ty}});

    bool visited[l][l];

    memset(visited,false,sizeof(visited));

    int df[8][2] = {{1, 2}, {-1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}};

    while(!q.empty()){
      pair<int, int> xy = q.front().second;
      int cnt = q.front().first;
      q.pop();
      if (xy.first == x && xy.second == y){
        cout << cnt << endl;
        break ;
      }
      for (int i = 0; i < 8; ++i) {
        int nx = xy.first + df[i][0];
        int ny = xy.second + df[i][1];

        if (nx >= 0 && nx < l && ny >= 0 && ny < l && !visited[nx][ny]){
          visited[nx][ny] = true;
          q.push({cnt + 1, {nx, ny}});
        }
      }
    }
  }
}