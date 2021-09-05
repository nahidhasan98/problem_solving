#include<bits/stdc++.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

struct st
{
    string CMD;
    char R1,R2;
    long long V;
};
vector<st>v;
long long memory[26];

int getVal(int pos,string s)
{
    long long v=0;

    for(int i=pos; i<s.size(); i++)
    {
        v*=10;
        v+=s[i]-48;
    }
    return v;
}

void processInput(string s)
{
    st temp;

    temp.R1='g';
    temp.R2='g';
    temp.V=999999;

    temp.CMD=s.substr(0,3);

    if(temp.CMD=="LOD")
    {
        temp.R1=s[4];

        if(s[6]=='-')
        {
            temp.V=getVal(7,s);
            temp.V*=-1;
        }
        else
            temp.V=getVal(6,s);
    }
    else if(temp.CMD=="INC")
    {
        temp.R1=s[4];
    }
    else if(temp.CMD=="ADD" || temp.CMD=="MUL" || temp.CMD=="CMP")
    {
        temp.R1=s[4];
        temp.R2=s[6];
    }
    else if(temp.CMD=="JMP" || temp.CMD=="JCZ" || temp.CMD=="JCP" || temp.CMD=="JCN")
    {
        temp.V=getVal(4,s);
    }

    v.push_back(temp);
}

void LOD(st temp)
{
    memory[temp.R1-65]=temp.V;
    memory['P'-65]++;
}
void INC(st temp)
{
    memory[temp.R1-65]++;
    memory['P'-65]++;
}
void ADD(st temp)
{
    memory[temp.R1-65]+=memory[temp.R2-65];
    memory['P'-65]++;
}
void MUL(st temp)
{
    memory[temp.R1-65]*=memory[temp.R2-65];
    memory['P'-65]++;
}
void JMP(st temp)
{
    if(temp.V<v.size())
        memory['P'-65]=temp.V;
    else
        memory['P'-65]++;
}
void CMP(st temp)
{
    long long X=memory[temp.R1-65];
    long long Y=memory[temp.R2-65];

    if(X==Y)
        memory['C'-65]=0;
    else if(X>Y)
        memory['C'-65]=1;
    else if(X<Y)
        memory['C'-65]=-1;

    memory['P'-65]++;
}
void JCZ(st temp)
{
    if(memory['C'-65]==0 && temp.V<v.size())
        memory['P'-65]=temp.V;
    else
        memory['P'-65]++;
}
void JCP(st temp)
{
    if(memory['C'-65]>0 && temp.V<v.size())
        memory['P'-65]=temp.V;
    else
        memory['P'-65]++;
}
void JCN(st temp)
{
    if(memory['C'-65]<0 && temp.V<v.size())
        memory['P'-65]=temp.V;
    else
        memory['P'-65]++;
}

void print()
{
    for(int i=0;i<6;i++)
        cout<<memory[i]<<' ';

    cout<<memory['P'-65]<<endl;
}

void executeProgram()
{
    for(int i=0;i<v.size();i++)
    {
        if(v[i].CMD=="LOD")
            LOD(v[i]);
        else if(v[i].CMD=="INC")
            INC(v[i]);
        else if(v[i].CMD=="ADD")
            ADD(v[i]);
        else if(v[i].CMD=="MUL")
            MUL(v[i]);
        else if(v[i].CMD=="JMP")
            JMP(v[i]);
        else if(v[i].CMD=="CMP")
            CMP(v[i]);
        else if(v[i].CMD=="JCZ")
            JCZ(v[i]);
        else if(v[i].CMD=="JCP")
            JCP(v[i]);
        else if(v[i].CMD=="JCN")
            JCN(v[i]);
        else if(v[i].CMD=="HLT")
            break;

        i=memory['P'-65]-1;
    }
}

int main()
{
    //FI FO

    st temp;
    string s;

    while(getline(cin,s))
    {
        processInput(s);
    }

    executeProgram();

    print();

    return 0;
}
