#include<bits/stdc++.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

long long table[100];

void calculate()
{
    table[0]=1;

    for(int i=1;i<=62;i++)
        table[i]=table[i-1]*2;

//    for(int i=0;i<=62;i++)
//        cout<<i<<' '<<table[i]<<endl;
}

int main()
{
    calculate();

    int test;
    cin>>test;

    for(int t=1; t<=test; t++)
    {
        long long l,r;
        cin>>l>>r;

        double left,right;

        double up=log2(r);
        double down=log2(l);

        if(floor(down)==ceil(down))
            left=down;
        else
            left=ceil(down);

        right=floor(up);

        long long sum=0;

        //cout<<left<<' '<<right<<endl;

        for(int i=left;i<=right;i++)
            sum+=table[i];

        cout<<sum<<endl;
    }

    return 0;
}
