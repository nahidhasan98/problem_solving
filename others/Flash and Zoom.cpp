#include<bits/stdc++.h>
using namespace std;

struct st
{
    int x,y;
};

//bool operator < (st a,st b)
//{
//    if(a.x!=)
//}

int main()
{
    int n;

    while(cin>>n)
    {
//        vector<st>vx,vy;
//        st temp;
//        int x;
//
//        for(int i=1;i<=n;i++)
//        {
//            cin>>temp.x>>temp.y;
//
//            vx.push_back(temp);
//
//            x=temp.x;
//            temp.x=temp.y;
//            temp.y=x;
//
//            vy.push_back(temp);
//        }
//        sort(v.begin(),v.end());


        vector<vector<int> >v(110),r(110);
        int x,y;

        for(int i=1;i<=n;i++)
        {
            cin>>x>>y;
            v[x].push_back(y);
            r[y].push_back(x);
        }
        for(int i=0;i<v.size();i++)
            sort(v[i].begin(),v[i].end());
        for(int i=0;i<r.size();i++)
            sort(r[i].begin(),r[i].end());

        long long area=0,peri=0,ll,lr,ul,ur;
        int ind[1000010]={0};

        for(int i=0;i<v.size();i++)
        {
            //cout<<i<<'=';
            for(int j=0;j<v[i].size()-1;j++)
            {
                x1=i,y1=v[i][j];
                x2=i,y2=v[i][j+1];
                x3=[ind[v[i][j+1]]],y3=v[i][j+1];
                x4=[r[v[i][j]][ind[v[i][j]]]],y3=v[i][j];


                ind[v[i][j]]++;
                ind[v[i][j+1]]++;
            }
        }
    }

    return 0;
}
