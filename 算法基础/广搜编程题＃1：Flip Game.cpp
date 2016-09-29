#include <iostream>
#include <bitset>
#include <queue>

using namespace std;
bitset<0x10000> repeat;
typedef bitset<16> FLIP;  //在coursera上不能直接 queue<bitset<16>> q;
queue<FLIP> q;
bitset<16> flip;

int BFS(int level)
{
    while(q.empty()==false)
    {
        int qlen=q.size();
        for(int i=0;i<qlen;i++)
        {
            bitset<16> temp(q.front());
            if(temp.to_ulong()==0xffff||temp.to_ulong()==0x0000)
                return level;
            for(int i=0;i<16;i++)
            {
                bitset<16> t(temp);
                int u=i-4,d=i+4,l=i-1,r=i+1;
                if(u>=0) t.flip(u);
                if(d<16) t.flip(d);
                if(l%4!=3&&l>=0) t.flip(l);
                if(r%4!=0&&r<16) t.flip(r);
                t.flip(i);
                if(repeat[t.to_ulong()]==0)
                {
                    repeat[t.to_ulong()]=1;
                    q.push(t);
                }
            }
            q.pop();
        }
        level++;
    }
    return -1;
}
int main()
{
  //  QCoreApplication a(argc, argv);
    for(int i=0;i<16;i++)
    {
        char c;
        cin>>c;
        if(c=='b') flip[i]=1;
        else if(c=='w') flip[i]=0;
    }
    q.push(flip);

    int result=BFS(0);
    if(result==-1) cout<<"Impossible"<<endl;
    else cout<<result<<endl;

    return 0;
}

