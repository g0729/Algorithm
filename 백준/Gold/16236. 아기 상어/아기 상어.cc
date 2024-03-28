#include<bits/stdc++.h>
using namespace std;
#define MAX 21
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int MAP[MAX][MAX];
bool visited[MAX][MAX];
int n;
pair<int,int>loc;
int cursize=2;
int cureat;
bool cmp(pair<int,int>a,pair<int,int>b)
{
   if(a.first==b.first)
   {
      return a.second<b.second;
   }
   return a.first<b.first;
}
int bfs()
{
   queue<pair<int,int>>q;
   q.push({loc.first,loc.second});
   int cnt=0;
   visited[loc.first][loc.second]=true;
   while(!q.empty())
   {
      int q_size=q.size();
      vector<pair<int,int>>fish;
      while(q_size--)
      {
         int x=q.front().first;
         int y=q.front().second;
         q.pop();
         for(int i=0;i<4;i++)
         {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<1||nx>n||ny<1||ny>n)
            continue;
            if(visited[nx][ny])
            continue;
            if(MAP[nx][ny]>cursize)
            continue;
            if(MAP[nx][ny]<cursize&&MAP[nx][ny]!=0)
            {
               fish.push_back({nx,ny});
            }
            q.push({nx,ny});
            visited[nx][ny]=true;
         }
      }
      cnt++;
      if(fish.size()==0)
      continue;
      sort(fish.begin(),fish.end(),cmp);
      loc.first=fish[0].first;
      loc.second=fish[0].second;
      MAP[loc.first][loc.second]=0;
      return cnt;
   }
   return -1;
}
int main()
{
   cin>>n;
   for (int i = 1; i <= n; i++)
   {
      for (int j = 1; j <= n; j++)
      {
         cin>>MAP[i][j];
         if(MAP[i][j]==9)
         {
            loc={i,j};
            MAP[i][j]=0;
         }
      }
   }

   int res=0;
   while(1)
   {
      int temp=bfs();
      if(temp==-1)
      break;
      res+=temp;
      cureat++;
      if(cureat==cursize)
      {
         cureat=0;
         cursize++;
      }
      memset(visited,0,sizeof(visited));
   }
   cout<<res;
}