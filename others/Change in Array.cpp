#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

struct st
{
    int l,r,x,y,exist;
};

bool operator < (st a,st b)
{
    if(a.l!=b.l)
        return a.l<b.l;
    else
        return a.r<b.r;
}

int main()
{
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int query;
    cin>>query;

    st q[query],l,r,x,y;

    for(int i=0;i<query;i++)
    {
        cin>>q[i].l>>q[i].r>>q[i].x>>q[i].y;
    }
    sort(q,q+query);

    for(int i=0;i<query;i++)
    {
        cout<<q[i].l<<' '<<q[i].r<<' '<<q[i].x<<' '<<q[i].y<<endl;
    }

    return 0;
}
/*

5
1 2 2 3 4
8
1 6 9 9
1 5 9 9
2 5 9 9
4 4 9 9
3 6 9 9
4 7 9 9
1 3 9 9
7 8 9 9

1 3 9 9
1 5 9 9
1 6 9 9
2 8
 9 9
3 6 9 9
4 4 9 9
4 7 9 9
7 8 9 9

*/
