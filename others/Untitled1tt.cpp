#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ar[2000],num1,num2;
    memset(ar,0,sizeof(ar));
    ar[1]=1;
    ar[2]=2;
    ar[3]=3;
    ar[4]=4;
    ar[5]=5;
    int con=6;
    for(int i=6; i<100000000; i++)
    {


        if(i%2==0&&(i%3==0||i%5==0))
        {
            ar[con]=i;
            con++;
        }
        if(con==1500+1)
            break;
    }
    int n;
    cin>>n;
    cout<<ar[n]<<endl;
    return 0;
}
