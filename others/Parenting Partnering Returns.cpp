#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int main()
{
    int test;
    cin>>test;

    for(int t=1; t<=test; t++)
    {
        int n;
        cin>>n;

        int start[n],finish[n],index[n];

        for(int i=0; i<n; i++)
        {
            cin>>start[i]>>finish[i];
            index[i]=i;
        }

        for(int i=0; i<n-1; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(start[i]==start[j])
                {
                    if(finish[i]>finish[j])
                    {
                        swap(start[i],start[j]);
                        swap(finish[i],finish[j]);
                        swap(index[i],index[j]);
                    }
                }
                else if(start[i]>start[j])
                {
                    swap(start[i],start[j]);
                    swap(finish[i],finish[j]);
                    swap(index[i],index[j]);
                }
            }
        }

        char res[n];
        int c=-1,j=-1,flag=0;

        for(int i=0; i<n; i++)
        {
            if(c<=j)
            {
                if(c<=start[i])
                {
                    res[index[i]]='C';
                    c=finish[i];
                }
                else
                {
                    flag=1;
                    break;
                }
            }
            else if(j<c)
            {
                if(j<=start[i])
                {
                    res[index[i]]='J';
                    j=finish[i];
                }
                else
                {
                    flag=1;
                    break;
                }
            }
        }

        if(flag==0)
        {
            cout<<"Case #"<<t<<": ";
            for(int i=0;i<n;i++)
                cout<<res[i];
            cout<<endl;
        }
        else
            cout<<"Case #"<<t<<": IMPOSSIBLE"<<endl;
    }

    return 0;
}
/*
1 100   J
2 5     C
99 150  C
100 301 J
150 250 C

2 4
1 5

11100 10 100 00

11100 10 100 00
00011 01 011 11
00001 00 001 11 ok
11110 11 110 00

*/
