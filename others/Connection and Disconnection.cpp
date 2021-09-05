#include<bits/stdc++.h>
using namespace std;

int check(string s)
{
    int counter=0;

    for(int i=1; i<s.size(); i++)
    {
        if(s[i]==s[i-1])
        {
            counter++;
            i++;
        }
    }
    return counter;
}

int main()
{
    string s;
    long long k;

    while(cin>>s>>k)
    {
        string temp=s;

        int first=check(s);

        s+=temp;
        int second=check(s)-first;

        s+=temp;
        int third=check(s)-(first+second);

        //cout<<first<<' '<<second<<' '<<third<<endl;

        long long res=0;

        if(k==1)
            res=first;
        else
        {
            res+=first;
            res+=second*(k/2);

            if(k%2==0)
                res+=third*((k/2)-1);
            else if(k%2!=0)
                res+=third*(k/2);
        }
        cout<<res<<endl;
    }

    return 0;
}
