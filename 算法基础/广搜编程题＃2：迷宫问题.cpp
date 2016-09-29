#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int maze[5][5];
int *pmaze=(int*)maze;
int visited[25];
int dist[25];
queue<int> q;
stack<int> s;
void BFS()
{
    q.push(0);
    visited[0]=1;
    dist[0]=0;
    while(!q.empty())
    {
        int npos=q.front();
        if(npos==24) break;
        if(npos-5>0&&visited[npos-5]==0)
        {
            q.push(npos-5);
            dist[npos-5]=dist[npos]+1;
            visited[npos-5]=1;
        }
       if((npos-1)%5!=4&&npos>0&&visited[npos-1]==0)
      {
           q.push(npos-1);
           dist[npos-1]=dist[npos]+1;
           visited[npos-1]=1;
       }
    if((npos+1)%5!=0&&npos<24&&visited[npos+1]==0)
    {
        q.push(npos+1);
        dist[npos+1]=dist[npos]+1;
        visited[npos+1]=1;
    }
    if(npos+5<25&&visited[npos+5]==0)
    {
        q.push(npos+5);
        dist[npos+5]=dist[npos]+1;
        visited[npos+5]=1;
    }
    q.pop();
   }
}

void findlastpoint(int npos)
{
    s.push(npos);
    if((npos-1)%5!=4&&npos>0&&dist[npos-1]==dist[npos]-1)
        findlastpoint(npos-1);
    if((npos+1)%5!=0&&npos<24&&dist[npos+1]==dist[npos]-1)
        findlastpoint(npos+1);
    if(npos-5>=0&&dist[npos-5]==dist[npos]-1)
        findlastpoint(npos-5);
    if(npos+5<25&&dist[npos+5]==dist[npos]-1)
        findlastpoint(npos+5);
}

int main()
{
    for(int i=0;i<25;i++)
    {
        cin>>pmaze[i];
        visited[i]=pmaze[i];
        dist[i]=100;
    }
    BFS();
    findlastpoint(24);
    while(!s.empty())
    {
        int npos=s.top();
        s.pop();
        cout<<"("<<npos/5<<", "<<npos%5<<")"<<endl;
    }

    return 0;
}

