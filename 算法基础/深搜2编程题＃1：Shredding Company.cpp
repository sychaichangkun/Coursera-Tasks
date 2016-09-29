//#include <QCoreApplication>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;
int target,maxsum=-1;
bool same;

vector<int> vec1,vec2;
int string2int(const char* c,int len)
{
    int sum=0;
    for(int i=0;i<len;i++)
    {
        int temp=*(c+i)-'0';
        for(int j=i;j<len-1;j++)
        {
            temp*=10;
        }
        sum+=temp;
    }
    return sum;
}

int DFS(const char* start,int len,int sum)
{
    for(int i=1;i<len;i++)
    {
        int temp=string2int(start,i);
        vec1.push_back(temp);
        DFS(start+i,len-i,sum+temp);
        vec1.pop_back();
    }
    int temp=string2int(start,len);
    sum+=temp;
    if(sum>=maxsum&&sum<=target)
    {
        if(sum==maxsum)
            same=true;
        else same=false;
        maxsum=sum;
        vec1.push_back(temp);
        vec2.clear();
        vec2=vec1;
        vec1.pop_back();
        return 0;
    }

}

int main(int argc, char *argv[])
{
 //   QCoreApplication a(argc, argv);
    string input;
    while(true)
    {
        maxsum=-1;
        same=false;
        cin>>target>>input;
        if(target==0&&input=="0")  return 0;

        DFS(input.c_str(),input.length(),0);
        if(same==true) cout<<"rejected"<<endl;
        else if(maxsum==-1)  cout<<"error"<<endl;
        else
        {
            cout<<maxsum<<" ";
            for(int i=0;i<vec2.size();i++)
                cout<<vec2[i]<<" ";
            cout<<endl;
        }
    }
}
