#include<bits/stdc++.h>
using namespace std;

struct st
{
    long long val,counter;
};

int main()
{
    long long n,k;

    while(cin>>n>>k)
    {
        long long a[n];

        for(int i=0;i<n;i++)
            cin>>a[i];

        sort(a,a+n);

        vector<st>v;
        st temp;
        temp.counter=1;
        int flag=0;

        for(int i=0;i<n-1;i++)
        {
            if(a[i]==a[i+1])
            {
                temp.val=a[i];
                temp.counter++;
                flag=1;
            }
            else
            {
                if(flag==1)
                {
                    v.push_back(temp);
                    flag=0;
                    temp.counter=1;
                }
                else
                {
                    temp.val=a[i];
                    v.push_back(temp);
                }
            }
        }
        if(a[n-1]==a[n-2])
        {
            v.push_back(temp);
        }
        else if(a[n-1]!=a[n-2])
        {
            temp.val=a[n-1];
            temp.counter=1;
            v.push_back(temp);
        }

        long long left=0,lcount=v[0].counter,lnext;
        long long right=v.size()-1,rcount=v[v.size()-1].counter,rnext;
        long long part=0;

        while(left<right && k>=1)
        {
//            cout<<"Left= "<<left<<" right= "<<right<<" k= "<<k<<' ';
//            cout<<"Lcount= "<<lcount<<" Rcount= "<<rcount<<endl;

            if(lcount<=rcount)
            {
                lnext=lcount*(v[left+1].val-v[left].val);

                if(lnext<=k)
                {
                    left++;
                    lcount+=v[left].counter;
                    k-=lnext;
                }
                else if(k<lnext)
                {
                    part=k/lcount;
                    k%=lcount;
                    break;
                }
            }
            else if(rcount<lcount)
            {
                rnext=rcount*(v[right].val-v[right-1].val);

                if(rnext<=k)
                {
                    right--;
                    rcount+=v[right].counter;
                    k-=rnext;
                }
                else if(k<rnext)
                {
                    part=k/rcount;
                    k%=rcount;
                    break;
                }
            }
        }
        long long res=v[right].val-v[left].val-part;
        cout<<res<<endl;
    }

    return 0;
}
