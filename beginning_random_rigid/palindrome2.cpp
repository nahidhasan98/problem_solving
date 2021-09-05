#include<bits/stdc++.h>
using namespace std;

int rev(int r);

int main()
{
    int first,last,count=0,i;

    cout<<"Enter the first number of series:\t";
    cin>>first;
    cout<<"\nNow enter the last number of series:\t";
    cin>>last;

    cout<<endl;

    for(i=first;i<=last;i++)
    {
        if(i==rev(i))
        {
            count++;
            cout<<i<<" ";
        }
    }

    cout<<"\n\nThere are total "<<count<<" palindrome number in the given series.\n";

    return 0;
}
int rev(int number)
{
    int reverse=0;

    while(number!=0)
    {
        reverse=reverse*10;
        reverse=reverse+number%10;
        number=number/10;
    }

    return reverse;
}
