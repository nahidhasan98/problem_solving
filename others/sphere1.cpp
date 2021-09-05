#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int test;
    cin>>test;

    for(int t=1; t<=test; t++)
    {
        double H,H1,H2;
        cin>>H>>H1>>H2;

        double pi=acos(-1);

        double R=H/2;
        double h1=H-H1;
        double h2=H-H2;

        vector<double>v;

        double totalVol=(4*pi*R*R*R)/3;

        double cap1=(pi*h1*h1*((3*R)-h1))/3;
        double cap2=(pi*h2*h2*((3*R)-h2))/3;

        double capVol=cap1;
        double segVol=cap2-cap1;
        double lowerVol=totalVol-(capVol+segVol);

//        double lowerMid=(pi*((2*R*R*R)-(3*R*h2*h2)+(h2*h2*h2)))/3;
//        cout<<lowerMid<<endl;
//        cout<<lowerVol-(totalVol/2)<<" is equal to "<<lowerMid<<endl;
//
//        cout<<"Cap vol= "<<capVol<<endl;
//        cout<<"Seg vol= "<<segVol<<endl;
//        cout<<"Lower vol= "<<lowerVol<<endl;
//        cout<<"Total vol= "<<totalVol<<" = "<<capVol+segVol+lowerVol<<endl;

        v.push_back(capVol);
        v.push_back(segVol);
        v.push_back(lowerVol);

        sort(v.begin(),v.end());

        cout<<"Case "<<t<<": ";
        cout<<fixed<<setprecision(6)<<v[0]<<' '<<v[1]<<' '<<v[2]<<endl;
    }

    return 0;
}
