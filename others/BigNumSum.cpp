#include<iostream>
#include<algorithm>
using namespace std;

string getSum(string a,string b)
{
    string res="";
    int carry = 0;

    for(int i=a.size()-1;i>=0;i--)
    {
        int temp = (a[i]-'0') + (b[i]-'0') + carry;

        if(temp>9)
        {
            res += (temp%10) + '0';
            carry = 1;
        }
        else
        {
            res += temp + '0';
            carry = 0;
        }
    }
    if(carry)
        res += carry + '0';

    reverse(res.begin(),res.end());

    return res;
}

int main()
{
    string a,b;

    while(cin>>a>>b)
        cout<<getSum(a,b)<<endl;

    return 0;
}
