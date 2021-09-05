#include<iostream>
using namespace std;

int process(int n, int z);

int main()
{
    int i,j,res=0;

    while(cin>>i>>j)
    {
        if(i<=j)
            res=process(i,j);
        else
            res=process(j,i);

        cout<<i<<" "<<j<<" "<<res<<endl;
    }

    return 0;
}
int process(int n, int z)
{
    int c,temp,k,pre=0;

    for(k=n;k<=z;k++)
    {
        temp=k;
        c=0;

        while(temp!=1)
        {
            c++;

            if(temp%2!=0)
                temp=(3*temp)+1;
            else
                temp=temp/2;
        }
        c++;

        if(pre>=c)
            pre=pre;
        else
            pre=c;
    }

    return pre;
}
