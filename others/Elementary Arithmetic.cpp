#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

string a,b;

void equalLength()
{
    int asz=a.size(),bsz=b.size();
    string temp="";

    for(int i=1;i<=abs(asz-bsz);i++)
        temp+='0';

    if(asz>bsz) b=temp+b;
    else if(asz<bsz) a=temp+a;
}

string getRes(string a,string b)
{
    //cout<<a<<' '<<b<<endl;

    string res="";
    int ad,bd,carry=0,temp=0;
    char c;

    for(int i=a.size()-1;i>=0;i--)
    {
        ad=a[i]-48,bd=b[i]-48;
        temp=ad+bd+carry;

        carry=temp/10;
        temp%=10;

        c=temp+48;

        res+=c;
    }

    if(carry==1)
        res+='1';

    reverse(res.begin(),res.end());

    return res;
}

int main()
{
    while(cin>>a>>b){
        equalLength();
        cout<<getRes(a,b)<<endl;
    }

    return 0;
}
