///no number will have contain leading zero
///there will be no operator sign(+,-,*) at the beginning & ending of the statement

#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

string s;
vector<string>vASM,vAS,vS,vFinal;
vector<char>optASM,optAS,optS;

string equalLength(string ori,int need)
{
    string ss="";

    for(int i=1; i<=need; i++)
        ss+='0';

    ss+=ori;
    return ss;
}

string subtraction(string a,string b)
{
    int flag=0;

    if(a.size()<b.size())
    {
        a=equalLength(a,b.size()-a.size());
        swap(a,b);
        flag=1;
    }
    else if(b.size()<a.size())
        b=equalLength(b,a.size()-b.size());

    string ss="";
    int sum=0,digit,carry=0,up=0,down;
    char c;

    //cout<<"a="<<a<<" b="<<b<<endl;

    for(int i=a.size()-1; i>=0; i--)
    {
        up=a[i]-48;

        down=b[i]-48;
        down+=carry;

        if(up<down)
        {
            up+=10;
            carry=1;
        }

        sum=up-down;

        c=sum+48;
        ss+=c;
    }

    reverse(ss.begin(),ss.end());

    if(flag==1)
        ss="-"+ss;

    return ss;
}

string addition(string a,string b)
{
    if(a.size()<b.size())
        a=equalLength(a,b.size()-a.size());
    else if(b.size()<a.size())
        b=equalLength(b,a.size()-b.size());

    string ss="";
    int sum,digit,carry=0;
    char c;

    //cout<<"a="<<a<<" b="<<b<<endl;

    for(int i=a.size()-1; i>=0; i--)
    {
        sum=(a[i]-48)+(b[i]-48);
        sum+=carry;

        digit=sum%10;
        carry=sum/10;

        c=digit+48;
        ss+=c;
    }
    if(carry>0)
    {
        c=carry+48;
        ss+=c;
    }
    reverse(ss.begin(),ss.end());
    return ss;
}

string multiplication(string a,string b)
{
    if(a.size()<b.size())
        swap(a,b);

    string ss="";
    int sum,digit,carry=0,step=0;
    char c;
    vector<string>v;

    for(int i=b.size()-1; i>=0; i--)
    {
        for(int j=1; j<=step; j++)
            ss+='0';

        for(int j=a.size()-1; j>=0; j--)
        {
            sum=(a[j]-48)*(b[i]-48);
            sum+=carry;

            digit=sum%10;
            carry=sum/10;

            c=digit+48;
            ss+=c;
        }
        if(carry>0)
        {
            c=carry+48;
            ss+=c;
        }
        step++;

        reverse(ss.begin(),ss.end());
        v.push_back(ss);

        ss="";
    }

    ss=v[0];
    for(int i=1; i<v.size(); i++)
    {
        ss=addition(ss,v[i]);
        //cout<<"per="<<ss<<endl;
    }

//    cout<<"vector:"<<endl;
//    for(int i=0; i<v.size(); i++)
//        cout<<v[i]<<endl;
//    cout<<"a="<<a<<" b="<<b<<endl;
    //cout<<"ss="<<ss<<"#"<<endl;
    return ss;
}

void allAddSub()
{
    cout<<"allAddSub Starting:"<<endl;

    vector<string>vPos,vNeg;

    vPos.push_back(vAS[0]);

    for(int i=0; i<optAS.size(); i++)
    {
        if(optAS[i]=='+')
            vPos.push_back(vAS[i+1]);
        else if(optAS[i]=='-')
            vNeg.push_back(vAS[i+1]);
    }

    string ssPos="",ssNeg="";
    ssPos=vPos[0];
    for(int i=1; i<vPos.size(); i++)
        ssPos=addition(ssPos,vPos[i]);

    if(vNeg.size()>0)
    {
        ssNeg=vNeg[0];
        for(int i=1; i<vNeg.size(); i++)
            ssNeg=addition(ssNeg,vNeg[i]);

        ssPos=subtraction(ssPos,ssNeg);
    }

    cout<<"allAddSub done"<<endl;

    cout<<ssPos<<endl;
    return;
}

void allMultiply()
{
    cout<<"allMultiply Starting:"<<endl;
    string ss="",pre="";
    int flag=0;

    for(int i=0; i<optASM.size(); i++)
    {
        cout<<"optASM=["<<i<<"]="<<optASM[i]<<endl;
        if(optASM[i]=='*')
        {
            if(flag==0)
            {
                ss=multiplication(vASM[i],vASM[i+1]);
                flag=1;
            }
            else if (flag==1)
            {
                ss=multiplication(pre,vASM[i+1]);
                flag=1;
            }
            if(i==optASM.size()-1)
                vAS.push_back(ss);
        }
        else
        {
            if(flag==0)
                vAS.push_back(vASM[i]);
            else if (flag==1)
                vAS.push_back(pre);

            optAS.push_back(optASM[i]);
            flag=0;

            if(i==optASM.size()-1)
                vAS.push_back(vASM[i+1]);
        }
        pre=ss;
        ss="";
    }
    cout<<"vectorAS:"<<endl;
    for(int i=0; i<vAS.size(); i++)
        cout<<vAS[i]<<endl;

    cout<<"multiplication done"<<endl;

    if(optAS.size()==0)
    {
        cout<<vAS[0]<<endl;
        return;
    }
    else
    {
        allAddSub();
    }
}

void separate()
{
    string ss="";

    for(int i=0; i<s.size(); i++)
    {
        if(s[i]!='+' && s[i]!='-' && s[i]!='*')
        {
            ss+=s[i];
        }
        else
        {
            optASM.push_back(s[i]);
            vASM.push_back(ss);
            ss="";
        }
    }
    vASM.push_back(ss);

    cout<<"separation done"<<endl;
    if(optASM.size()==0)
    {
        cout<<s<<endl;
        return;
    }
    else
    {
        allMultiply();
    }
//    for(int i=0;i<vASM.size();i++){
//        cout<<vASM[i]<<' '<<optASM[i]<<endl;
//    }
}

int main()
{
    FI
    int test=1;

    while(cin>>s)
    {
        vASM.clear(),vAS.clear(),vS.clear(),vFinal.clear();
        optASM.clear(),optAS.clear(),optS.clear();

        cout<<"Case "<<test<<": #################";
        separate();
        cout<<endl;

        test++;
    }

    return 0;
}
/*
    2342342
      21321
-----------
    2342342     2432432
   4684684x     04864864
  7027026xx     006207207
 2342342xxx     0002432432
4684684xxxx     00004864864
-----------
49941073782



435534
139874
-------
295660
*/
