#include<bits/stdc++.h>
using namespace std;

struct st
{
    int x,y;
};

bool operator < (st a, st b)
{
    if(a.x!=b.x)
        return a.x<b.x;
    else
        return a.y<b.y;
}

int main()
{
    int test;
    cin>>test;

    for(int t=1; t<=test; t++)
    {
        int n,counter=0;
        cin>>n;

        st a[n];

        for(int i=0; i<n; i++)
            cin>>a[i].x>>a[i].y;

        if(n<=2)
            counter=1;
        else
        {
            sort(a,a+n);

            cout<<endl;
            for(int i=0;i<n;i++)
                cout<<a[i].x<<' '<<a[i].y<<endl;

//            int visited[n]= {0},counter=1;
//
//            for(int i=1; i<n; i++)
//            {
//                if(a[i].x-)
//                    if(a[i].x==a[i-1].x)
//                        continue;
//                    else
//                    {
//                        e
//                    }
//            }
        }
        cout<<"Case "<<t<<": "<<counter<<endl;
    }

    return 0;
}
