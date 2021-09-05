#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

vector<long long>v;

struct st
{
    long long number;
};

bool operator < (st a,st b)
{
    if(a.number!=b.number)
        return a.number>b.number;
    else
        return a.number<b.number;
}

void calculate(long long n)
{
    long long last=0;
    st temp,f;
    priority_queue<st>pq;

    temp.number=n;
    pq.push(temp);

    while(v.size()<1505)
    {
        f=pq.top();
        pq.pop();

        if(f.number!=last)
        {
            v.push_back(f.number);

            temp.number=f.number*2;
            pq.push(temp);

            temp.number=f.number*3;
            pq.push(temp);

            temp.number=f.number*5;
            pq.push(temp);
        }
        last=f.number;
    }

//    sort(v.begin(),v.end());
//
//    cout<<v.size()<<endl;
//    for(int i=0;i<v.size();i++)
//        cout<<v[i]<<endl;
}

int main()
{
    //FO

    calculate(1);

    int n;

    while(cin>>n)
    {
        if(n==0)
            return 0;

        cout<<v[n-1]<<endl;
    }

    return 0;
}
/*
2
2 3 5
4,6,10,3,5 ->3 4 5 6 10
6,9,15,4,5,6,10 -> 4 5 6 6 9 10 15

*/
