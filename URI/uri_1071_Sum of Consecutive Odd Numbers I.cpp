#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x,y;

    while(cin>>x>>y)
    {
        int sum=0;

        if(x>y)
        {
            int temp=x;
            x=y;
            y=temp;
        }

        if(x%2!=0)
            x=x+2;

        else if(x%2==0)
            x+=1;

        for(int i=x;i<y;i+=2)
        {
            sum=sum+i;
        }
        cout<<sum<<endl;
    }

    return 0;
}
