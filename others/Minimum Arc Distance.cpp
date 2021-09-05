#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    for(int T=1;T<=t;T++)
    {
        double ox,oy,ax,ay,bx,by,pi=acos(-1);
        cin>>ox>>oy>>ax>>ay>>bx>>by;

        double radius=sqrt(((ox-bx)*(ox-bx))+((oy-by)*(oy-by)));
        double points_distance=sqrt(((ax-bx)*(ax-bx))+((ay-by)*(ay-by)));

        double center_angle=acos(((2*radius*radius)-(points_distance*points_distance))/(2*radius*radius));
        //double center_angle=2*asin((.5*points_distance)/radius);

        double angle_in_degree=(center_angle*180)/pi;

        double res=(2*pi*radius*angle_in_degree)/360;


        cout<<"Case "<<T<<": "<<fixed<<setprecision(6)<<res<<endl;
    }

    return 0;
}
