#include<bits/stdc++.h>
using namespace std;

int main()
{
    int ax,ay,bx,by,cx,cy;

    while(cin>>ax>>ay>>bx>>by>>cx>>cy)
    {
        int minx,midx,maxx,miny,midy,maxy;

        if(ax<=bx && bx<=cx)
        {
            minx=ax;
            midx=bx;
            maxx=cx;
        }
        else if(ax<=bx && cx<=bx)
        {
            maxx=bx;

            if(ax<=cx)
            {
                minx=ax;
                midx=cx;
            }
            else
            {
                minx=cx;
                midx=ax;
            }
        }
        else if(ax<=cx && cx<=bx)
        {
            maxx=bx;

            if(ax<=cx)
            {
                minx=ax;
                midx=cx;
            }
            else
            {
                minx=cx;
                midx=ax;
            }
        }
    }

    return 0;
}
