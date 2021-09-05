#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

void print(vector<int>digit)
{
    for(int i=0;i<digit.size();i++)
        cout<<digit[i]<<' ';
    cout<<endl;
}

bool checkPrime(int num)
{
    bool isPrime = true;

    for(int i=2;i<sqrt(num);i++)
    {
        if(num%i==0)
            return isPrime = false;
    }

    return isPrime;
}

int permuteAndCheck(vector<int>digit)
{
    int flag=0;

    sort(digit.begin(),digit.end());

    do{
        //print(digit);

        if(digit[0]!=0){
            int num=0;

            for(int i=0;i<digit.size();i++){
                num *= 10;
                num += digit[i];
            }

            if(checkPrime(num))
            {
                flag=1;
                return num;
            }
        }
    } while (next_permutation(digit.begin(),digit.end()));

    return flag;
}

int main()
{
    char c;
    vector<int>digit;

    for(int i=1;i<11;i++)
    {
        cin>>c;

        if(c=='*')
            digit.push_back(i%10);
    }

    int result=permuteAndCheck(digit);

    if(!result)
        cout<<":-("<<endl;
    else
        cout<<result<<endl;

    return 0;
}
