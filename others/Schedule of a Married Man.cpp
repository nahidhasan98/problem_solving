#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin>>test;

    for(int t=1;t<=test;t++)
    {
        int wf_start_h,wf_start_m,wf_end_h,wf_end_m;
        int of_start_h,of_start_m,of_end_h,of_end_m;
        char c;

        cin>>wf_start_h>>c>>wf_start_m;
        cin>>wf_end_h>>c>>wf_end_m;

        cin>>of_start_h>>c>>of_start_m;
        cin>>of_end_h>>c>>of_end_m;

        int wf_start=(wf_start_h*60)+wf_start_m;
        int wf_end=(wf_end_h*60)+wf_end_m;

        int of_start=(of_start_h*60)+of_start_m;
        int of_end=(of_end_h*60)+of_end_m;

        if(of_start>wf_end || of_end<wf_start)
            cout<<"Case "<<t<<": Hits Meeting"<<endl;
        else
            cout<<"Case "<<t<<": Mrs Meeting"<<endl;
    }

    return 0;
}
