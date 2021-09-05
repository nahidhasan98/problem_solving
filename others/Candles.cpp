#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

vector<int>v;
vector<string>serial;
vector<vector<vector<int>>>possible(101);
vector<map<string,bool>>memory(101);

long long convertToDigit(string s)
{
    long long res=0;

    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='1')
        {
            res*=10;
            res+=9-i;
        }
    }
    return res;
}
void solve()
{
    long long res=1e12;

    for(int i=0; i<serial.size(); i++)
    {
        int flag=0;
        for(int j=0; j<v.size(); j++)
        {
            if(memory[v[j]][serial[i]]!=true)
            {
                flag=1;
                break;
            }
        }

        if(flag==0)
            res=min(res,convertToDigit(serial[i]));
    }
    cout<<res<<endl;
}
void checkAndStore(int num,int a,int b=-1)
{
    vector<int>temp;

    while(a!=0)
    {
        temp.push_back(a%10);
        a/=10;
    }

    if(b!=-1)
    {
        while(b!=0)
        {
            temp.push_back(b%10);
            b/=10;
        }
    }

    int flag=0;
    for(int i=0; i<temp.size(); i++)
    {
        for(int j=i+1; j<temp.size(); j++)
        {
            if(temp[i]==temp[j])
            {
                flag=1;
                break;
            }
        }
    }
    if(flag==0)
    {
//        for(int i=0;i<temp.size();i++)
//            cout<<"temp="<<temp[i]<<' ';
//        cout<<"temp End"<<endl;
        possible[num].push_back(temp);
    }
}
void preProcess()
{
    for(int i=1; i<=100; i++)                               //100
    {
        for(int j=1; j<=i/2; j++)
            checkAndStore(i,j,i-j);
        checkAndStore(i,i); //the number itself

        //finding all possible way according to binary serial combination
        for(int j=0; j<possible[i].size(); j++)             //100*16
        {
            for(int k=0; k<serial.size(); k++)              //100*16*1024
            {
                int flag=0;
                for(int l=0; l<possible[i][j].size(); l++)  //100*16*1024*4
                {
                    //cout<<"possible["<<i<<"]["<<j<<"]["<<l<<"]="<<possible[i][j][l]<<' '<<serial[k]<<endl;
                    if(serial[k][9-possible[i][j][l]]!='1')
                    {
                        flag=1;
                        break;
                    }
                }
                if (flag==0)
                    memory[i][serial[k]]=true;
            }
        }
    }
}
string doEqualLength(string s)  //making 10 length
{
    string res="";

    for(int i=1; i<=10-s.size(); i++)
        res+="0";

    res+=s;
    return res;
}
void createBinSerial()
{
    //this function will generate binary serial
    queue<string>q;
    q.push("1");

    for(int i=1; i<1024; i++)
    {
        string s1=q.front();
        q.pop();

        serial.push_back(doEqualLength(s1));

        string s2=s1;

        s1+="0";
        q.push(s1);

        s2+="1";
        q.push(s2);
    }
}
int main()
{
    createBinSerial();
    preProcess();

//    for(int i=0; i<memory.size(); i++)
//    {
//        cout<<"num="<<i<<endl;
//        map<string,bool>::iterator it;
//        for(it=memory[i].begin(); it!=memory[i].end(); it++)
//            cout<<it->first<<' '<<it->second<<' ';
//        cout<<endl;
//    }

    int n,tc=0;
    while(cin>>n)
    {
        if(n==0)
            return 0;

        v.clear();
        int d;

        for(int i=0; i<n; i++)
        {
            cin>>d;
            v.push_back(d);
        }

        cout<<"Case "<<++tc<<": ";
        solve();
    }

    return 0;
}
/*
0000000001 ->   0
0000000010 ->   1
0000000011 ->  10
0000000100 ->   2
0000000101 ->  20
0000000110 ->  21
0000000111 -> 210
*/
/*
10|         9876543210
1 9    ok   1000000010 > 514
2 8    ok   0100000100 > 260
3 7    ok   0010001000 > 136
4 6    ok   0001010000 >  80    ok
10     ok   0000000011 >   3

11|
2 9    ok   1000000100 > 516
3 8    ok   0100001000 > 264
4 7    ok   0010010000 > 144
5 6    ok   0001100000 >  96    ok

result      0001110000 > 112
*/
