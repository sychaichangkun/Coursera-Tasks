#include <iostream>
#include <algorithm>
using namespace std;
long int N,S;
long int *C=NULL;
long int *Y=NULL;
long int mincostofweeki(long int i)
{
    long int min=C[0]+i*S;
    for(long int j=1;j<=i;j++)
    {
        if((C[j]+(i-j)*S)<min)
        {
            min=C[j]+(i-j)*S;
        }
    }
    return min*Y[i];
}
long int  mincostofNweek(long int  n)
{
    long int  sum=0;
    for(long int i=0;i<n;i++)
    {
        sum+=mincostofweeki(i);
    }
    return sum;
}

int main()
{

    cin>>N>>S;
    C=new long int[N];
    Y=new long int[N];
    for(long int i=0;i<N;i++)
    {
        cin>>C[i]>>Y[i];
    }

    cout<<mincostofNweek(N)<<endl;

    return 0;
}

