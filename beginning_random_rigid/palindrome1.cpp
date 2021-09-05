#include<bits/stdc++.h>
using namespace std;

int rev(int r);

int main()
{
    int number,count=0,sum=0;

    cout<<"Enter an integer number:\t";
    cin>>number;

    while(number!=rev(number))
    {
        cout<<"\nn="<<number<<endl;
        cout<<"Reverse n="<<rev(number)<<endl;

        cout<<"This is not palindrome."<<endl;

        sum=number+rev(number);
        cout<<"sum is "<<sum<<endl;

        number=sum;
        count++;
    }
    cout<<"\nThis is palindrome.\n";

    cout<<"After adding "<<count<<" time, it becomes palindrome.\n";

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
