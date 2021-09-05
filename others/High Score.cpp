#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int test;
    cin>>test;

    for(int t=1; t<=test; t++)
    {
        string s;
        cin>>s;

        int total=s.size()-1;

        for(int i=0; i<s.size(); i++)
        {
            if(s[i]<='N')
            {
                //cout<<s[i]-'A'<<endl;
                total+=s[i]-'A';
            }
            else
            {
                //cout<<('Z'-s[i])+1<<endl;
                total+=('Z'-s[i])+1;
            }
        }
        int tempL=0,tempR=0;
        for(int i=s.size()-1; i>0; i--)
        {
            if(s[i]=='A')
                tempL++;
            else
                break;
        }
        for(int i=1; i<s.size()-1; i++)
        {
            if(s[i]=='A')
                tempR++;
            else
                break;
        }
        total-=max(tempL,tempR);

        int left=0,right=0,mx=0,flag=0,fixL=0,fixR=0,sum=0,exist=0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='A' && flag==0)
            {
                left=i;
                right=i;
                flag=1;
                exist=1;
            }
            else if(s[i]=='A' && flag==1)
            {
                right=i;
            }
            else
            {
                if(flag==1)
                    sum=(right-left)+1;

                flag=0;

                if(sum>mx)
                {
                    mx=sum;
                    fixL=left;
                    fixR=right;
                    sum=0;
                }
            }
        }
        if(flag==1)
        {
            sum=(right-left)+1;
            flag=0;

            if(sum>mx)
            {
                mx=sum;
                fixL=left;
                fixR=s.size()-1;
            }
        }

        int lengthL=fixL-1,lengthR=s.size()-fixR-1,sumL=0,sumR=0;
        if(lengthL<0)
            lengthL=0;

        for(int i=1; i<fixL; i++)
        {
            if(s[i]<='N')
                sumL+=s[i]-'A';
            else
                sumL+=('Z'-s[i])+1;
        }
        for(int i=s.size()-1; i>fixR; i--)
        {
            if(s[i]<='N')
                sumR+=s[i]-'A';
            else
                sumR+=('Z'-s[i])+1;
        }

        int common=0;
        if(s[0]<='N')
            common=s[0]-'A';
        else
            common=('Z'-s[0])+1;

        int l=0,r=0;

        if(lengthL==0)
            l=common+sumL+sumR+lengthR;
        else
            l=common+sumL+sumR+(lengthL*2)+lengthR;

        if(lengthR==0)
            r=common+sumL+sumR+lengthL;
        else
            r=common+sumL+sumR+(lengthR*2)+lengthL;

        int broken_total=min(l,r);

        cout<<"fix_pos "<<fixL<<' '<<fixR<<' '<<mx<<endl;
        cout<<"Lenght "<<lengthL<<' '<<lengthR<<endl;
        cout<<"suml-r "<<sumL<<' '<<sumR<<endl;
        cout<<"L_R "<<l<<' '<<r<<endl;
        cout<<"total "<<total<<endl;

        if(fixL==0 && fixR==0 && exist==0)
            cout<<total<<endl;
        else
            cout<<min(total,broken_total)<<endl;
    }

    return 0;
}
///ABCDEFGHIJKLMNOPQRSTUVWXYZ
///GAAAAAAAAALAAAAXAAALAAAAAAAAAAAAAAAVAAAAAAAAAAAA
///AAAAAAAAAAAAGALAAAAAAAAAAAAAKAAAAAAAAAKXAAAA
///KSAEAAAAZASSUAAAAFA
