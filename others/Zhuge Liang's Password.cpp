#include<bits/stdc++.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int n,a[35][35],b[35][35],c[35][35];

void rotate90()
{
    //cout<<"Hello "<<n<<endl;
    int row=0,col=0;

    for(int j=0; j<n; j++)
    {
        for(int i=n-1; i>=0; i--)
        {
            c[row][col]=b[i][j];
            col++;
        }
        row++;
        col=0;
        //cout<<"loop"<<endl;
    }

//    cout<<"Rotate"<<endl;
//    for(int i=0; i<n; i++)
//    {
//        for(int j=0; j<n; j++)
//            cout<<c[i][j]<<' ';
//        cout<<endl;
//    }
}

void restoreTob()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            b[i][j]=c[i][j];
    }
}

int check()
{
    int counter=0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(a[i][j]==c[i][j])
                counter++;
        }
    }
    return counter;
}

int main()
{
    while(cin>>n)
    {
        if(n==0)
            break;

        int res=0,counter=0;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                cin>>a[i][j];
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>b[i][j];

                if(b[i][j]==a[i][j])
                    counter++;
            }
        }
        res=max(res,counter);
        //cout<<"1:"<<res<<endl;

        for(int i=1; i<=3; i++)
        {
            rotate90();
            res=max(res,check());

            restoreTob();

            //cout<<i+1<<":"<<res<<endl;
        }

        cout<<res<<endl;
    }

    return 0;
}
/*

3
1 2 3
4 5 6
7 8 9

9 8 7
6 5 4
3 2 1

2
1 2
3 4
5 6
7 8
2
10 20
30 13
90 10
13 21
*/
