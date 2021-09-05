#include<bits/stdc++.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int main()
{
    FI FO
    int test;
    cin>>test;

    for(int t=1;t<=test;t++)
    {
        int n;
        cin>>n;

        int mn[8]={0,0,1,7,4,2,6,8};

        if(n<=7)
            cout<<mn[n]<<' ';
        else if(n%7==0)
        {
            for(int i=1;i<=n/7;i++)
                cout<<"8";
            cout<<' ';
        }
        else if(n>14 && n%7==3)
        {
            cout<<"200";

            for(int i=1;i<=(n/7)-2;i++)
                cout<<"8";
            cout<<' ';
        }
        else
        {
            string modMin[8]={"0","10","18","22","20","28","68","88"};
            int temp=n;

            int mod=temp%7;

            string s="";
            s+=modMin[mod];

            for(int i=1;i<(temp/7);i++)
                s+='8';

            cout<<s<<' ';
        }

        string s="";

        if(n%2!=0)
        {
            s+='7';
            n-=3;
        }
        while(n>0)
        {
            s+='1';
            n-=2;
        }

        cout<<s<<endl;
    }

    return 0;
}

/*
min
2=1
3=7
4=4
5=2
6=0
7=8
8=10
9=18
10=22
11=20
12=28
13=68
14=88
15=108
16=188
17=200
18=208
19=288
20=688
21=888
22=1088
23=1888
24=2008
25=2088
26=2888
27=8088
28=8888
29=
30=

1=2
7=3
4=4
2=5
3=5
5=5
0=6
6=6
9=6
8=7

100
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
98
99
100
2

*/
