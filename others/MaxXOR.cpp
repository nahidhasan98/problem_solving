#include<bits/stdc++.h>

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

using namespace std;

int trie[3100005][2];
int stringID[3100005];
int id=1;
vector<int>v;

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

    for(int i=s.size()-1;i>=0;i--)
    {
        if(s[i]=='1') res+=powerTwo;

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

void buildTrie(string s,int index)
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
        else row=trie[row][col];
    }
    stringID[row]=index+1;
}

void processQuery()
{
    int q,d,row,col,res;
    cin>>q;

    string s,temp;

    for(int i=1; i<=q; i++)
    {
        cin>>d;

        s=decToBin(d);
        s=equalLength(s);

        temp="";
        row=0;

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

        cout<<"Query "<<i<<": ";
        cout<<stringID[row]<<' ';
        cout<<res<<endl;
    }
}

int main()
{
    //FI FO

    memset(trie,-1,sizeof(trie));
    memset(stringID,-1,sizeof(stringID));

    int n,d;
    cin>>n;

    string s;

    for(int i=0; i<n; i++)
    {
        cin>>d;
        v.push_back(d);

        s=decToBin(d);
        s=equalLength(s);

        buildTrie(s,i);
    }

    processQuery();

    return 0;
}
/*
5
3 4 8 13 6
2
4
11
*/
