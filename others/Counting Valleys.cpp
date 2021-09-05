#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int countingValleys(int steps, string path)
{
    int pre=0,counter=0,result=0;

    for(int i=0; i<path.size(); i++)
    {
        pre=counter;

        if(path[i]=='U')
            counter++;
        else
            counter--;

        if(counter==0 && pre<0)
            result++;
    }

    return result;
}

int main()
{
    FI

    int steps;
    string s;

    cin>>steps>>s;

    cout<<countingValleys(steps,s);

    return 0;
}
