#include <iostream>
using namespace std;
int fibonacci(int n)
{
    if (n==1)
    {
        return 1;
        cout<<1<<" ";
    }
    else if (n==2)
    {
        return 1;
        cout<<1<<" ";
    }
    else
    {
        return (fibonacci(n-1)+fibonacci(n-2));
        cout<<fibonacci(n-1)+fibonacci(n-2)<<" ";
    }
}
int main()
{
    int n;
    cin>>n;
    fibonacci(n);

    return 0;
}
