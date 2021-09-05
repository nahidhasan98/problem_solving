#include<bits/stdc++.h>
using namespace std;

double dis(double x1,double y1,double x2,double y2)
{
    double res=sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));

    return res;
}

int main()
{
    int test;
    cin>>test;

    for(int t=1; t<=test; t++)
    {
        double ax,ay,sx,sy,px,py;
        cin>>ax>>ay>>sx>>sy>>px>>py;

        ///down fence processing
        double mid,down_Midx,down_Midy;

        mid=((abs(sx-px))*sy)/(sy+py);

        if(sx<=px) down_Midx=sx+mid;
        else down_Midx=sx-mid;

        down_Midy=0;

        ///right fence processing
        double right_Midx,right_Midy;

        mid=((abs(sy-py))*(ax-sx))/((ax-sx)+(ax-px));
        right_Midx=ax;

        if(sy<=py) right_Midy=sy+mid;
        else right_Midy=sy-mid;

        ///up fence processing
        double up_Midx,up_Midy;

        mid=((abs(sx-px))*(ay-sy))/((ay-sy)+(ay-py));

        if(sx<=px) up_Midx=sx+mid;
        else up_Midx=sx-mid;

        up_Midy=ay;

        ///left fence processing
        double left_Midx,left_Midy;

        mid=((abs(sy-py))*sx)/(sx+px);
        left_Midx=0;

        if(sy<=py) left_Midy=sy+mid;
        else left_Midy=sy-mid;

        ///Measuring distance
        double down=dis(sx,sy,down_Midx,down_Midy)+dis(down_Midx,down_Midy,px,py);
        double right=dis(sx,sy,right_Midx,right_Midy)+dis(right_Midx,right_Midy,px,py);
        double up=dis(sx,sy,up_Midx,up_Midy)+dis(up_Midx,up_Midy,px,py);
        double left=dis(sx,sy,left_Midx,left_Midy)+dis(left_Midx,left_Midy,px,py);

        double res=min(min(down,right),min(up,left));

        cout<<fixed<<setprecision(6)<<res<<endl;
    }

    return 0;
}
