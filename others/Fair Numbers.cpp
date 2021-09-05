    #include<iostream>
    #include<stdio.h>
    #include<vector>
    #include<algorithm>
    #include<cmath>
    using namespace std;

    #define FI freopen("in.txt","r",stdin);
    #define FO freopen("out.txt","w",stdout);

    int main()
    {
        int test;
        cin>>test;

        for(int t=1; t<=test; t++)
        {
            long long n,temp;
            cin>>n;

            for(long long i=n; i<=(n+2530); i++)
            {
                long long temp=i;
                vector<int>v;
                while(temp!=0)
                {
                    v.push_back(temp%10);
                    temp/=10;
                }

                int flag=0;
                for(int j=0; j<v.size(); j++)
                {
                    if(v[j]!=0 && i%v[j]!=0)
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    cout<<i<<endl;
                    break;
                }
            }
        }

        return 0;
    }
    /*
    4
    1
    282
    1234567890
    1234567900
    1000000000000000000

    */
