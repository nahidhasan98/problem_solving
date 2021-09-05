#include<bits/stdc++.h>

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

using namespace std;

int trie[5000000][2];
int id=1;

string decToBin(int num)
{
    string s="";
    int r;

    while(num!=0)
    {
        r=num%2;
        s+=r+48;
        num/=2;
    }
    reverse(s.begin(),s.end());

    return s;
}

int binToDec(string s)
{
    int res=0,powerTwo=1;

    for(int i=s.size()-1; i>=0; i--)
    {
        if(s[i]=='1')
            res+=powerTwo;

        powerTwo*=2;
    }
    return res;
}

string equalLength(string s)
{
    int need=31-s.size();
    string res="";

    for(int i=1; i<=need; i++)
        res+='0';

    res+=s;

    return res;
}

void buildTrie(string s)
{
    int row=0,col;

    for(int i=0; i<s.size(); i++)
    {
        col=s[i]-48;

        if(trie[row][col]==-1)
        {
            trie[row][col]=id;
            row=id;

            id++;
        }
        else
            row=trie[row][col];
    }
}

int findMax(string s)
{
    int row=0,col,res;
    string temp="";

    for(int j=0; j<s.size(); j++)
    {
        col=s[j]-48;

        if(trie[row][!col]!=-1)
        {
            temp+='1';
            row=trie[row][!col];
        }
        else if(trie[row][!col]==-1)
        {
            temp+='0';
            row=trie[row][col];
        }
    }
    res=binToDec(temp);

    //cout<<"Max="<<res<<endl;
    return res;
}

int findMin(string s)
{
    int row=0,col,res;
    string temp="";

    for(int j=0; j<s.size(); j++)
    {
        col=s[j]-48;

        if(trie[row][col]!=-1)
        {
            temp+='0';
            row=trie[row][col];
        }
        else if(trie[row][col]==-1)
        {
            temp+='1';
            row=trie[row][!col];
        }
    }
    res=binToDec(temp);

    //cout<<"Min="<<res<<endl;
    return res;
}

int main()
{
    //FI FO

    int test;
    cin>>test;

    for(int t=1; t<=test; t++)
    {
        memset(trie,-1,sizeof(trie));

        int n,mx=0,mn=1e9;
        cin>>n;

        int a[n],cumulativeXor[n];
        string s;

        if(n==1)
        {
            cin>>a[0];
            mx=a[0];
            mn=a[0];
        }
        else
        {
            for(int i=0; i<n; i++)
            {
                cin>>a[i];

                if(i==0)
                    cumulativeXor[i]=a[i];
                else
                    cumulativeXor[i]=cumulativeXor[i-1]^a[i];

                s=decToBin(cumulativeXor[i]);
                s=equalLength(s);

                if(i==0)
                {
                    mx=cumulativeXor[i];
                    mn=cumulativeXor[i];
                }
                else
                {
                    mx=max(mx,max(cumulativeXor[i],findMax(s)));
                    mn=min(mn,min(cumulativeXor[i],findMin(s)));
                }
                buildTrie(s);
            }
        }
        cout<<"Case "<<t<<": "<<mx<<' '<<mn<<endl;
    }

    return 0;
}
/*
2
5
6 8 2 4 2
5
3 8 2 6 5
*/
