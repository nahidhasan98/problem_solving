#include<iostream>
using namespace std;

int main()
{
    int i,j,k,c,res,temp,n;

    while(cin>>i>>j)
    {
        if(i<=j)
        {
            i=i;
            j=j;
        }
        else
        {
            temp=i;
            i=j;
            j=temp;
        }
        res=0;

        for(k=i;k<=j;k++)
        {
            n=k;
            c=0;

            while(n!=1)
            {
                c++;

                if(n%2!=0)
                    n=(3*n)+1;
                else
                    n=n/2;
            }
            c++;

            if(res>=c)
                res=res;
            else
                res=c;
        }
        cout<<i<<" "<<j<<" "<<res<<endl;
    }

    return 0;
}
