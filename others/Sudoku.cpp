#include<bits/stdc++.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int main()
{
    int test;
    cin>>test;

    for(int t=1; t<=test; t++)
    {
        string s[9];

        for(int i=0; i<9; i++)
            cin>>s[i];

        int flag=1;
        //int check[10]= {0};
        map<char,int>check;

        for(int i=0; i<9; i++)
        {
            //memset(check,0,sizeof(check));
            check.clear();

            for(int j=0; j<9; j++)
                check[s[i][j]]++;

            for(char k='1'; k<='9'; k++)
            {
                if(check[k]==0)
                {
                    flag=0;
                    break;
                }
            }
            if(flag==0)
                break;
        }
        //cout<<"row= "<<flag<<endl;
        for(int j=0; j<9; j++)
        {
            //memset(check,0,sizeof(check));
            check.clear();

            for(int i=0; i<9; i++)
                check[s[i][j]]++;

            for(char k='1'; k<='9'; k++)
            {
                if(check[k]==0)
                {
                    flag=0;
                    break;
                }
            }
            if(flag==0)
                break;
        }
        //cout<<"col= "<<flag<<endl;
        //memset(check,0,sizeof(check));
        check.clear();
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
                check[s[i][j]]++;
        }
        for(char k='1'; k<='9'; k++)
        {
            if(check[k]==0)
            {
                flag=0;
                break;
            }
        }

        //memset(check,0,sizeof(check));
        check.clear();
        for(int i=0; i<3; i++)
        {
            for(int j=3; j<6; j++)
                check[s[i][j]]++;
        }
        for(char k='1'; k<='9'; k++)
        {
            if(check[k]==0)
            {
                flag=0;
                break;
            }
        }

        //memset(check,0,sizeof(check));
        check.clear();
        for(int i=0; i<3; i++)
        {
            for(int j=6; j<9; j++)
                check[s[i][j]]++;
        }
        for(char k='1'; k<='9'; k++)
        {
            if(check[k]==0)
            {
                flag=0;
                break;
            }
        }

        //memset(check,0,sizeof(check));
        check.clear();
        for(int i=3; i<6; i++)
        {
            for(int j=0; j<3; j++)
                check[s[i][j]]++;
        }
        for(char k='1'; k<='9'; k++)
        {
            if(check[k]==0)
            {
                flag=0;
                break;
            }
        }
        //memset(check,0,sizeof(check));
        check.clear();
        for(int i=3; i<6; i++)
        {
            for(int j=3; j<6; j++)
                check[s[i][j]]++;
        }
        for(char k='1'; k<='9'; k++)
        {
            if(check[k]==0)
            {
                flag=0;
                break;
            }
        }
        //memset(check,0,sizeof(check));
        check.clear();
        for(int i=3; i<6; i++)
        {
            for(int j=6; j<9; j++)
                check[s[i][j]]++;
        }
        for(char k='1'; k<='9'; k++)
        {
            if(check[k]==0)
            {
                flag=0;
                break;
            }
        }

        //memset(check,0,sizeof(check));
        check.clear();
        for(int i=6; i<9; i++)
        {
            for(int j=0; j<3; j++)
                check[s[i][j]]++;
        }
        for(char k='1'; k<='9'; k++)
        {
            if(check[k]==0)
            {
                flag=0;
                break;
            }
        }
        //memset(check,0,sizeof(check));
        check.clear();
        for(int i=6; i<9; i++)
        {
            for(int j=3; j<6; j++)
                check[s[i][j]]++;
        }
        for(char k='1'; k<='9'; k++)
        {
            if(check[k]==0)
            {
                flag=0;
                break;
            }
        }
        //memset(check,0,sizeof(check));
        check.clear();
        for(int i=6; i<9; i++)
        {
            for(int j=6; j<9; j++)
                check[s[i][j]]++;
        }
        for(char k='1'; k<='9'; k++)
        {
            if(check[k]==0)
            {
                flag=0;
                break;
            }
        }

        if(flag==1)
            cout<<"Valid"<<endl;
        else
            cout<<"Invalid"<<endl;
    }

    return 0;
}
