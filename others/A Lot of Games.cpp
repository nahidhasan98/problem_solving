#include<bits/stdc++.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int trie[1000010][26];
int id=1;

int convert(char c)
{
    return c-97;
}

void buildTrie(string s)
{
    int row=0,col;

    for(int j=0; j<s.size(); j++)
    {
        col=convert(s[j]);

        if(trie[row][col]==-1)
        {
            trie[row][col]=id;
            row=id;
            id++;
        }
        else
        {
            row=trie[row][col];
        }
    }
}

string recursive(int source)
{
    string res="win",temp="";
    int row=source;

    for(int i=0; i<26; i++)
    {
        if(trie[row][i]!=-1)
        {
            temp=recursive(trie[row][i]);

            if(temp=="win")
                res="loss";
        }
    }

    return res;
}

int main()
{
    int n,k;

    while(cin>>n>>k)
    {
        memset(trie,-1,sizeof(trie));

        string s;

        for(int i=0; i<n; i++)
        {
            cin>>s;
            buildTrie(s);
        }

        string res="Second";

        for(int i=0; i<26; i++)
        {
            if(trie[0][i]!=-1)
            {
                if(recursive(trie[0][i])=="win")
                {
                    res="First";
                    break;
                }
            }
        }
        if(res=="First")
        {
            if(k%2==0)
                res="Second";
        }
        cout<<res<<endl;
    }

    return 0;
}
/*
4 2
aaaa
bbbb
ccccc
dumbavumba

Ans: First
*/
