#include<bits/stdc++.h>
using namespace std;

int a[1000100],b[1000100];
//int check(int);

int check(int z)
{
    int flag=0;

    for(int j=2;j<=sqrt(z);j++)
    {
        if(z%j==0)
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
        return 1;
    else
        return 0;
}

int main()
{
    int n,x=1,p,q,m;

    for(int i=2;i<1000000;i++)
    {
        if(check(i)==1)
        {
            a[i]=i;
            b[x]=i;
            x++;
        }
        else
            a[i]=0;
    }

    while(cin>>n)
    {
        if(n==0)
            return 0;
        else
        {
            int flag2=0;

            for(int k=2;k<=n;k++)
            {
                if(a[k]!=0)
                {
                    q=n-a[k];

                    for(int m=0;b[m]<=n;m++)
                    {
                        if(q==b[m])
                        {
                            p=a[k];
                            flag2=1;
                            break;
                        }
                    }
                    if(flag2==1)
                        break;
                }
            }
            if(flag2==0)
                cout<<"Goldbach's conjecture is wrong."<<endl;
            else
                cout<<n<<" = "<<p<<" + "<<q<<endl;
        }
    }

    return 0;
}

