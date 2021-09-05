#include<bits/stdc++.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);


struct inp
{
    string s1,s2;
};
struct cnum
{
    char c;
    int num;
};

cnum separate(string s)
{
    char c=s[0];
    int sum=1;

    for(inr i=1;i<s.size();i++)
    {
        sum*=10;
        sum+=s[i]+48;
    }
    cnum temp;

    temp.c=c;
    temp.num=sum;

    return temp;
}
int solve(int pos,int cat,int dog)
{
    int x=0,y=0;

    cnum t1=separate(a[pos].s1);
    cnum t2=separate(a[pos].s2);

    x=solve(pos+1,a[pos].s1,a[pos].s2);
    y=solve(pos+1,,);
}

int main()
{
    int test;
    cin>>test;

    for(int t=1;t<=test;t++)
    {
        int c,d,v;
        cin>>c>>d>>v;

        inp a[v];

        for(int i=0;i<v;i++)
        {
            cin>>a[i].s1>>a[i].s2;
        }

        cout<<solve(0,cat,dog);

        cout<<"Case "<<t<<": "<<<<endl;
    }

    return 0;
}
