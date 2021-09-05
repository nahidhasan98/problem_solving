#include<bits/stdc++.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int trie[5000010][26];
int counter[5000010];
int mark[5000010];
int endingPoint[5000010];
int id=1;
string last="";

struct st
{
    bool isExist,isEndingPoint;
    int counter,midRow;
    string s;
};

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
            counter[id]++;
            row=id;

            id++;
        }
        else
        {
            counter[trie[row][col]]++;
            row=trie[row][col];
        }
    }
    endingPoint[row]=1;
}

int markingBottomUp(int row)
{
    int res=0,flag=0;

    for(int i=0; i<26; i++)
    {
        if(trie[row][i]!=-1)
        {
            res=max(res,markingBottomUp(trie[row][i]));
            flag=1;
        }
    }
    if(flag==0)
        return mark[row]=counter[row];

    return mark[row]=res;
}

int getCount(int row)
{
    int sum=0;
    for(int i=0; i<26; i++)
    {
        if(trie[row][i]!=-1)
        {
            sum+=counter[trie[row][i]];
        }
    }
    return counter[row]-sum;
}

st uptoPrefix(string s)
{
    st temp;
    temp.isExist=true;
    temp.isEndingPoint=false;

    int row=0,col;

    for(int j=0; j<s.size(); j++)
    {
        col=convert(s[j]);

        if(trie[row][col]==-1)
        {
            temp.isExist=false;
            break;
        }
        else
            row=trie[row][col];
    }

    if(endingPoint[row]==1)
        temp.isEndingPoint=true;

    temp.midRow=row;
    temp.counter=getCount(row);

    return temp;
}

st afterPrefix(int row,string part)
{
    st temp3;
    char c;
    int next=0,temp=0;

    for(int i=0; i<26; i++)
    {
        if(trie[row][i]!=-1)
        {
            temp=mark[trie[row][i]];

            if(temp>next)
            {
                next=trie[row][i];
                c=i+97;
            }
        }
    }

    if(next!=0)
    {
        part+=c;
        return afterPrefix(next,part);
    }
    else
    {
        temp3.s=part;
        temp3.counter=mark[row];
        return temp3;
    }
}

int main()
{
    int n;

    while(cin>>n)
    {
        memset(trie,-1,sizeof(trie));
        memset(counter,0,sizeof(counter));
        memset(mark,0,sizeof(mark));
        memset(endingPoint,0,sizeof(endingPoint));

        string s;

        for(int i=0; i<n; i++)
        {
            cin>>s;
            buildTrie(s);
        }

        markingBottomUp(0);

        int q;
        cin>>q;

        for(int i=1;i<=q;i++)
        {
            cin>>s;
            st temp1=uptoPrefix(s);

            if(!temp1.isExist)
                cout<<"Case "<<i<<": -1"<<endl;
            else
            {
                cout<<"Case "<<i<<": ";

                st temp2=afterPrefix(temp1.midRow,"");
                //cout<<temp1.counter<<' '<<temp2.counter<<endl;

                if(temp1.counter>=temp2.counter)
                    cout<<s<<' '<<temp1.counter<<endl;
                else
                    cout<<s<<temp2.s<<' '<<temp2.counter<<endl;
            }
        }
    }

    return 0;
}
/*

*/
