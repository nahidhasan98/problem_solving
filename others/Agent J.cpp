#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int t;
    cin>>t;

    for(int T=1;T<=t;T++)
    {
        double r1,r2,r3,pi=acos(-1);
        cin>>r1>>r2>>r3;

        double tri_a=r1+r2;
        double tri_b=r2+r3;
        double tri_c=r3+r1;

        double tri_peri_half=(tri_a+tri_b+tri_c)/2;

        double tri_area=sqrt(tri_peri_half*(tri_peri_half-tri_a)*(tri_peri_half-tri_b)*(tri_peri_half-tri_c));

        //double tri_height=sqrt((tri_c*tri_c)-(r3*r3));

        //double tri_area=(tri_b*tri_height)/2;

        cout<<tri_area<<endl;

        double cir_1_area=pi*(r1*r1);
        double cir_2_area=pi*(r2*r2);
        double cir_3_area=pi*(r3*r3);

        double cir_1_part=(cir_1_area*60)/360;
        double cir_2_part=(cir_2_area*60)/360;
        double cir_3_part=(cir_3_area*60)/360;

        double cir_area=cir_1_part+cir_2_part+cir_3_part;

        cout<<cir_1_part<<' '<<cir_2_area<<' '<<cir_3_part<<' '<<cir_area<<endl;

        double dia_area=tri_area-cir_area;

        cout<<"Case "<<T<<": "<<fixed<<setprecision(7)<<dia_area<<endl;
    }

    return 0;
}
