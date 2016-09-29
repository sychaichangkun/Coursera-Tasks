#include <iostream>
#include <algorithm>
using namespace std;
int N,C;
int* pos=NULL;

bool check(int d,int N,int C)
{
    int last=pos[0];
    int cows=1;
    for(int i=0;i<N;i++)
    {
        if(pos[i]-last>=d)
        {
            cows++;
            last=pos[i];
        }
    }
    if(C<=cows)
        return true;
    else
        return false;
}
int main()
{

    cin>>N>>C;
    pos=new int[N];
    for(int i=0;i<N;i++)
    {
        cin>>pos[i];
    }
    sort(pos,pos+N);

    int l=1,r=pos[N-1]-pos[0]+1;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(l+1>=r) break;
        if(check(mid,N,C))
        {
            l=mid;
        }
        else
        {
            r=mid;
        }
    }
    cout<<l<<endl;

    return 0;
}

