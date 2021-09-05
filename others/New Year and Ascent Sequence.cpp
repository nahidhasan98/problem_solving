#include<bits/stdc++.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int main()
{
    int n;

    while(cin>>n)
    {
        int l,d,ascent=0;
        vector<int>mini,maxi;

        for(int i=0; i<n; i++)
        {
            cin>>l;

            int dmini=1e7,dmaxi=-1,flag=0;

            for(int j=0; j<l; j++)
            {
                cin>>d;

                if(d>dmini)
                    flag=1;

                dmini=min(dmini,d);
                dmaxi=max(dmaxi,d);
            }

            if(flag==1)
                ascent++;
            else
            {
                mini.push_back(dmini);
                maxi.push_back(dmaxi);
            }
        }

        sort(maxi.begin(),maxi.end());
        long long counter=0;

        for(int i=0; i<ascent; i++)
        {
            counter+=(2*(n-i))-1;
        }
        //cout<<"Half counter="<<counter<<endl;

        for(int i=0; i<mini.size(); i++)
        {
            int low=0,high=maxi.size()-1,mid;

            while(low<=high)
            {
                mid=(low+high)/2;
                //cout<<"low="<<low<<" mid="<<mid<<" high="<<high <<endl;

                if(mini[i]<maxi[mid])
                    high=mid-1;
                else if(mini[i]>=maxi[mid])
                    low=mid+1;
            }
            if(maxi[mid]<=mini[i])
                counter+=maxi.size()-(mid+1);
            else if(maxi[mid]>mini[i])
                counter+=maxi.size()-mid;

            //cout<<"i= "<<i<<" counter="<<counter<<endl;
        }

        cout<<counter<<endl;
    }

    return 0;
}
