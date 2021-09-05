#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

const int mxSize = 1e5 + 5;
int tree[mxSize*3];

void update(int node, int rangeLeft, int rangeRight, int idx, int value)
{
    //cout<<"call: node="<<node<<" rl="<<rangeLeft<<" rr="<<rangeRight<<" idx="<<idx<<" value="<<value<<endl;
    if (rangeLeft > idx || rangeRight < idx)    //out of range
        return;
    if (rangeLeft == rangeRight)  //relevant idx
    {
        if (value < 0)
            tree[node] = 0;
        else
            tree[node] += value;

        return;
    }

    int rangeMid = (rangeLeft + rangeRight) / 2;
    int left = node * 2;
    int right = (node * 2) + 1;

    update(left, rangeLeft, rangeMid, idx, value);
    update(right, rangeMid+1, rangeRight, idx, value);

    tree[node] = tree[left] + tree[right];
}

int query(int node, int rangeLeft, int rangeRight, int i, int j)
{
    if (rangeLeft > j || rangeRight < i)    //out of range
        return 0;
    if (rangeLeft >= i && rangeRight <= j)  //relevant segment
        return tree[node];

    //cout<<"call: node="<<node<<" rl="<<rangeLeft<<" rr="<<rangeRight<<" i="<<i<<" j="<<j<<endl;
    int rangeMid = (rangeLeft + rangeRight) / 2;
    int left = node * 2;
    int right = (node * 2) + 1;

    int a = query(left, rangeLeft, rangeMid, i, j);
    int b = query(right, rangeMid+1, rangeRight, i, j);

    return a + b;
}

int main()
{
    //FI FO

    int test;
    cin>>test;

    for (int t = 1; t <= test; t++)
    {
        memset(tree,0,sizeof(tree));

        int n,q;
        cin>>n>>q;

        int arr[n+1];
        for (int i = 1; i <= n; i++)
        {
            cin>>arr[i];
            update(1, 1, n, i, arr[i]);

//            cout<<"i="<<i<<endl;
//            for (int i = 1; i <= 30; i++)
//                cout<<tree[i]<<' ';
//            cout<<endl;
        }

        cout<<"Case "<<t<<":"<<endl;

        int comm,i,j,v;
        for (int k = 0; k < q; k++)
        {
            cin>>comm;

            if (comm == 1)
            {
                cin>>i;
                cout<<query(1, 1, n, i+1, i+1)<<endl;
                update(1, 1, n, i+1, -1);
            }
            else if (comm == 2)
            {
                cin>>i>>v;
                update(1, 1, n, i+1, v);
            }
            else
            {
                cin>>i>>j;
                cout<<query(1, 1, n, i+1, j+1)<<endl;
            }

//            cout<<"k="<<k<<endl;
//            for (int ii = 1; ii <= 30; ii++)
//                cout<<tree[ii]<<' ';
//            cout<<endl;
        }
    }

    return 0;
}
