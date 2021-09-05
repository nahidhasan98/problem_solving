#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin>>test;

    for(int t=1; t<=test; t++)
    {
        double ax,ay,bx,by,cx,cy,ix,iy,jx,jy;
        cin>>ax>>ay>>bx>>by>>cx>>cy>>ix>>iy>>jx>>jy;

        double hx,hy,fx,fy;

        hx=(3*ix)-ax-cx;
        hy=(3*iy)-ay-cy;
        fx=(3*jx)-bx-cx;
        fy=(3*jy)-by-cy;

        double disAC,disBC,disHU,m,rm,b,ux,uy;

        disAC=sqrt(((cx-ax)*(cx-ax))+((cy-ay)*(cy-ay)));
        disBC=sqrt(((cx-bx)*(cx-bx))+((cy-by)*(cy-by)));

        m=(cy-ay)/(cx-ax);

        if(m==0)
            disHU=abs(hy-ay);
        else if(ax==bx && bx==cx)
            disHU=abs(hx-ax);
        else
        {
//            rm=(-1.0)/m;
//            b=hy-(rm*hx);
//
//            ux=(((rm*hx)+b)-(ay-(m*ax)))/m;
//            uy=(m*ux)+(ay-(m*ax));
//
//            disHU=sqrt(((hx-ux)*(hx-ux))+((hy-uy)*(hy-uy)));

            ux=(hx+(m*hy)-(m*(ay-(m*ax))))/((m*m)+1);
            uy=(m*ux)+(ay-(m*ax));
            disHU=sqrt(((hx-ux)*(hx-ux))+((hy-uy)*(hy-uy)));
//            cout<<ux<<' '<<uy<<endl;
//
//            ux=(fx+(m*fy)-(m*(ay-(m*ax))))/((m*m)+1);
//            uy=(m*ux)+(ay-(m*ax));
//            disHU=sqrt(((hx-ux)*(hx-ux))+((hy-uy)*(hy-uy)));
//            cout<<ux<<' '<<uy<<endl;
        }

        double area1=disAC*disHU;
        double area2=disBC*disHU;

        double res=abs(area1-area2);

        cout<<fixed<<setprecision(9)<<res<<endl;
    }

    return 0;
}
