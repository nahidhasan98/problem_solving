#include<bits/stdc++.h>
using namespace std;

struct em
{
    int id,salary;
};

bool operator < (em aa, em bb)
{
    if(aa.salary!=bb.salary)
        return aa.salary>bb.salary;
    else
        return bb.salary>aa.salary;
}

int main()
{
    int n,d,k;

    cin>>n>>d>>k;

    em a[n];
    string name[n];

    for(int i=0; i<n; i++)
    {
        cin>>name[i]>>a[i].salary;

        a[i].id=i;
    }

    sort(a,a+n);

    int sum=0,x=-1;

    for(int i=0; i<k; i++)
    {
        sum+=a[i].salary;

        if(sum>=d)
        {
            x=i+1;
            break;
        }
    }
    if(x==-1)
        cout<<"impossible"<<endl;
    else
    {
        cout<<x<<endl;

        for(int i=0; i<x; i++)
            cout<<name[a[i].id]<<", YOU ARE FIRED!"<<endl;
    }

    return 0;
}
