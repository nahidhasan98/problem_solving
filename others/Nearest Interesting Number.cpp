#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a;

    while(cin>>a)
    {
        int flag=0;

        while(1)
        {
            int temp=a,sum=0;

            while(temp!=0)
            {
                sum+=temp%10;
                temp/=10;
            }
            if(sum%4==0)
            {
                flag=1;
                break;
            }
            a++;
        }
        cout<<a<<endl;
    }

    return 0;
}
