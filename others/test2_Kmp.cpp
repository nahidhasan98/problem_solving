///Sailful////////////////////////////////////

///kmp ////////////////////////////////////

#include<bits/stdc++.h>
using namespace std;
int con;
int main()
{
    string t,p;
    cin>>t>>p;
    int st,sp;
    st=t.size();
    sp=p.size();
    int ind[sp];
    memset(ind,0,sizeof(ind));
    ind[0]=0;

    for(int i=0,j=1; j<sp; j++)
    {
        if(p[i]==p[j])
        {
            ind[j]=i+1;
            i++;
        }
        else
        {
            if(i>0)
                j--;

            if(i>0)
                i=ind[i-1];
        }
    }

    for(int i=0,j=0; j<st; j++)
    {
        cout<<"p["<<i<<"]="<<p[i]<<" t["<<j<<"]="<<t[j]<<endl;
        //cout<<"i="<<i<<" j="<<j<<endl;
        if(p[i]==t[j])
        {
            i++;
            con++;
        }
        else
        {
            if(i>0)
                j--;
            if(i>0)
                i=ind[i-1];

            cout<<endl;
        }
        if(i==sp)
        {
            cout<<"Matching Position :"<<j-i+1<<endl;
            break;
        }
    }
    return 0;
}
/*
abcxabcdabxabcdabcdabcx
abcdabcx
*/

///dijsktra///////////////////////////////////////////

#include<bits/stdc++.h>
using namespace std;
vector<int>v[100];
int wet[100][100];
int vis[100];
int dis[100]= {99999999};
struct  st
{
    int p;
    int w;
};
bool operator < (st x,st y)
{
    if(x.w > y.w)
        return true;
    return false;
//    if(x.w!=y.w)
//    {
//        return x.w>y.w;
//    }
//    else
//    {
//        return x.w<y.w;
//    }
}
void diskta(int sorce,int n)
{
    for(int i=0; i<100; i++)
    {
        vis[i]=0;
        dis[i]=999999;
    }
    vis[sorce]=1;
    dis[sorce]=0;
    priority_queue<st>pq;
    st obj;
    obj.w=dis[sorce];
    obj.p=sorce;
    pq.push(obj);
    //cout<<"ss"<<endl;
    while(!pq.empty())
    {
        st ob;
        ob=pq.top();
        //cout<<"pop="<<ob.p<<endl;
        pq.pop();
        for(int i=0; i<v[ob.p].size(); i++)
        {
            //cout<<"ss"<<endl;
            //cout<<"dis["<<v[ob.p][i]<<"]="<<dis[v[ob.p][i]]<<" dis["<<ob.p<<"]="<<dis[ob.p]<<" wet["<<ob.p<<"]["<<v[ob.p][i]<<"]="<<wet[ob.p][v[ob.p][i]]<<endl;
            if(dis[v[ob.p][i]]>(dis[ob.p]+wet[ob.p][v[ob.p][i]]))
            {
                dis[v[ob.p][i]]=(dis[ob.p]+wet[ob.p][v[ob.p][i]]);
                //cout<<"dis="<<dis[v[ob.p][i]]<<endl;
                st op;
                op.p=v[ob.p][i];
                op.w=dis[v[ob.p][i]];
                pq.push(op);
            }

        }
        //cout<<"endl"<<endl;
    }
//cout<<"distance="<<endl;
    for(int i=1; i<=n; i++)
        cout<<"dis[<<"i<<"]="<<dis[i]<<endl;
}
int main()
{
    int edge,node;
    cin>>edge>>node;
    int a,b,w;
    for(int i=0; i<edge; i++)
    {
        cin>>a>>b>>w;
        v[a].push_back(b);
        v[b].push_back(a);
        wet[a][b]=w;
        wet[b][a]=w;
    }
    diskta(1,node);
    return 0;
}

///Edit distance///////////////////////////////////////////

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int l1,l2;
    l1=s1.size();
    l2=s2.size();
    int ar[l1][l2];
    for(int i=0; i<l2; i++)
        ar[0][i]=i+1;

    for(int i=0; i<l1; i++)
        ar[i][0]=i+1;

    for(int i=1; i<l1; i++)
    {
        for(int j=1; j<l2; j++)
        {
            if(s1[i-1]==s2[j-1])
                ar[i][j]=ar[i-1][j-1];
            else
            {
                int temp=min(ar[i-1][j],ar[i][j-1]);
                ar[i][j]=min(temp,ar[i-1][j-1])+1;
            }
        }
    }
    for(int i=0; i<l1; i++)
    {
        for(int j=0; j<l2; j++)
            cout<<ar[i][j]<<" ";

        cout<<endl;
    }
    cout<<endl;

    cout<<ar[l1-1][l2-1]<<endl;
    return 0;
}

///lcs for two string/////////////////////////////////////

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int l1,l2;
    l1=s1.size();
    l2=s2.size();
    int ar[l1][l2];
    for(int i=0; i<l2; i++)
        ar[0][i]=0;

    for(int i=0; i<l1; i++)
        ar[i][0]=0;

    for(int i=1; i<l1; i++)
    {
        for(int j=1; j<l2; j++)
        {
            if(s1[i-1]==s2[j-1])
                ar[i][j]=max(ar[i][j-1],ar[i-1][j])+1;
            else
                ar[i][j]=max(ar[i][j-1],ar[i-1][j]);
        }
        //cout<<endl;
    }
    for(int i=0; i<l1; i++)
    {
        for(int j=0; j<l2; j++)
            cout<<ar[i][j]<<" ";

        cout<<endl;
    }
    cout<<endl;

    return 0;
}

///MST //////////////////////////////////////////////

#include<bits/stdc++.h>
using namespace std;
int vist[10000]= {0};
struct st
{
    int id;
    int wt;
};

bool operator < (st x,st y)
{
    if(x.wt!=y.wt)
        return x.wt>y.wt;
    else
        return x.wt<y.wt;
}
void prims(int sorce,vector<int>vc[10000],vector<int>w[10000])
{
    priority_queue<st>pq;
    for(int i=0; i<vc[sorce].size(); i++)
    {
        st obj;
        obj.id=vc[sorce][i];
        obj.wt=w[sorce][i];
        //cout<<"w["<<sorce<<"]["<<i<<"]="<<w[sorce][i]<<endl;
        pq.push(obj);
    }
    vist[sorce]=1;
    cout<<"pt="<<sorce<<" ";
    while(!pq.empty())
    {
        st ob;
        ob=pq.top();

        pq.pop();
        //cout<<"vist[ob.id]="<<ob.id<<endl;
        if(vist[ob.id]==0)
        {
            cout<<ob.id<<" ";
            vist[ob.id]=1;
            for(int i=0; i<vc[ob.id].size(); i++)
            {
                st ob2;
                ob2.id=vc[ob.id][i];
                ob2.wt=w[ob.id][i];
                if(vist[ob2.id]==0)
                    pq.push(ob2);
            }
        }
    }
    cout<<endl;
}
int main()
{
    int node,edge;
    cin>>node>>edge;
    int a,b,wet;
    vector<int>vc[10000];
    vector<int>w[10000];
    for(int i=0; i<edge; i++)
    {
        cin>>a>>b>>wet;
        if(b!=a)
        {
            vc[a].push_back(b);
            vc[b].push_back(a);
            //int k=min(wet,w[a][i]);
            w[a].push_back(wet);
            w[b].push_back(wet);
        }
    }
    prims(1,vc,w);
    return 0;
}

///ncr//////////////////////////////////////

#include<iostream>
#include<cstring>
#include<math.h>
using namespace std;
int ar[100005];
int br[100005];
int cr[100005];
int dr[100005];
long long ph(int a,int b)
{
    long long sum=1;
    for(int i=0; i<b; i++)
        sum*=a;

    return sum;
}
int main()
{
    memset(ar,0,sizeof(ar));
    for(int i=2; i<=100000; i++)
    {
        if(ar[i]!=1)
        {
            ar[i]=0;
            for(int j=i*2; j<=100000; j=j+i)
                ar[j]=1;
        }
    }
    int n,k;
    while(cin>>n>>k)
    {
        if(n==0&&k==0)
            break;

        if(n>100000)
        {
            if(k==0)
                cout<<"1"<<endl;
            else if(k==1)
                cout<<n<<endl;
            else if(k==n)
                cout<<"1"<<endl;
            else
                cout<<n<<endl;
        }
        else
        {
            memset(br,0,sizeof(br));
            memset(cr,0,sizeof(cr));
            memset(dr,0,sizeof(dr));
            for(int i=2; i<=n; i++)
            {
                if(ar[i]==0)
                {
                    br[i]+=n/i;
                    //cout<<"br[i]="<<br[i]<<endl;
                    if(i<=k)
                        cr[i]+=k/i;

                    if(i<=(n-k))
                        dr[i]+=(n-k)/i;
                    // cout<<"br[i]="<<br[i]<<endl;
                    int j=0;
                    j=i*i;
                    while(j<=n)
                    {
                        br[i]+=n/j;
                        if(j<=k)
                            cr[i]+=k/j;
                        if(j<=(n-k))
                            dr[i]+=(n-k)/j;
                        j*=i;
                    }

                }
            }
//        for(int i=2;i<=n-k;i++)
//        {
//            if(ar[i]!=1)
//            {
//                cout<<i<<"="<<dr[i]<<" ";
//            }
//        }
//        cout<<endl;
            for(int i=2; i<=k; i++)
            {
                if(ar[i]==0)
                {
                    br[i]-=cr[i];
                    // cout<<br[i]<<endl;
                }
            }
            for(int i=2; i<=n-k; i++)
            {
                if(ar[i]==0)
                {
                    br[i]-=dr[i];
                    //cout<<"br[i]="<<br[i]<<endl;
                }
            }
            long long sum=1;
            for(int i=2; i<=n; i++)
            {
                if(ar[i]==0)
                {
                    if(br[i]!=0)
                        sum*=ph(i,br[i]);
                }

            }
            cout<<sum<<endl;
        }
    }
    return 0;
}

/// Nahid /////////////////////////////////////

///coin change 1 ////////////////////////////

#include<bits/stdc++.h>
using namespace std;

int n,k,a[60],c[60],data[1010][60];

int solve(int k,int i)
{
    if(k==0)
        return 1;
    if(i>=n)
        return 0;
    if(data[k][i]!=-1)
        return data[k][i];

    int x=0,y=0;
    for(int j=1;j<=c[i];j++)
    {
        if(k>=(a[i]*j))
            x+=(solve(k-(a[i]*j),i+1))%100000007;
        y=solve(k,i+1)%100000007;
    }
    return data[k][i]=(x+y)%100000007;
}
int main()
{
    int t;
    cin>>t;

    for(int T=1;T<=t;T++)
    {
        memset(data,-1,sizeof(data));

        cin>>n>>k;

        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            cin>>c[i];

        int res=solve(k,0);

        cout<<"Case "<<T<<": "<<res<<endl;
    }

    return 0;
}

/// z array /////////////////////////////////

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;

    while(cin>>s)
    {
        int sz=s.size();

        int arr[sz+5];
        memset(arr,0,sizeof(arr));

        int z[sz];
        z[0]=0;

        int l=1,r=1;

        for(int i=1;i<sz;i++)
        {
            if(i>=r)
            {
                l=i;
                r=i;
                int temp=i,sum=0;

                for(int j=0;j<sz;j++)
                {
                    if(s[j]==s[temp])
                    {
                        sum++;
                        temp++;
                    }
                    else
                        break;
                }
                z[i]=sum;
                arr[z[i]]++;
            }
            else
            {
                z[i]=min(z[i-l],r-i);

                if(z[i]>r-i)
                {
                    int temp=r-i,sum=0,j;

                    for(j=r;j<sz;j++)
                    {
                        if(s[temp]==s[j])
                        {
                            sum++;
                            temp++;
                        }
                        else
                            break;
                    }
                    z[i]=z[i]+sum;
                    r=j;
                    l=i;
                }
                arr[z[i]]++;
            }
        }
        int fix=-1,k=1;
        for(int i=sz-1;i>=1;i--)
        {
            if(sz-i==z[i])
            {
                if(arr[z[i]]>=2)
                    fix=i;
            }
        }
        if(fix==-1)
            cout<<"Just a legend"<<endl;
        else
        {
            string res=s.substr(fix);
            cout<<res<<endl;
        }
    }

    return 0;
}

/// suffix array //////////////////////////////////

#include<bits/stdc++.h>
using namespace std;

struct letter
{
    int index,f,s;
};
bool operator < (letter a,letter b)
{
    if(a.f!=b.f)
        return a.f<b.f;
    else
        return a.s<b.s;
}

int main()
{
    string s;

    while(cin>>s)
    {
        int sz=s.size();

        letter a[sz];

        for(int i=0;i<sz;i++)
        {
            a[i].index=i;
            a[i].f=s[i]-96;
            a[i].s=-1;
        }

        int sum=1,limit=0;
        while(limit<sz)
        {
            sum=sum*2;
            limit++;
        }

        for(int k=0;k<=limit;k++)
        {
            sort(a,a+sz);

            int identity[sz];
            memset(identity,0,sizeof(identity));

            for(int i=0;i<sz;i++)
                identity[a[i].index]=i;

            letter temp[sz];
            for(int i=0;i<sz;i++)
            {
                temp[i].f=a[i].f;
                temp[i].s=a[i].s;
            }

            int numbering=1;
            a[0].f=numbering;

            for(int i=1;i<sz;i++)
            {
                if(temp[i].f==temp[i-1].f && temp[i].s==temp[i-1].s)
                    a[i].f=numbering;
                else
                {
                    numbering++;
                    a[i].f=numbering;
                }
            }
            for(int i=0;i<sz;i++)
            {
                int next_index=(a[i].index+pow(2,k));

                if(next_index<sz)
                    a[i].s=a[identity[next_index]].f;
                else
                    a[i].s=-1;
            }
        }
        for(int i=0;i<sz;i++)
            cout<<a[i].index<<endl;

        cout<<endl;
    }

    return 0;
}
