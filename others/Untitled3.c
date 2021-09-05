#include<bits/stdc++.h>
 using namespace std;

 int oi;
 int main()
 {
   int n,x,in=0;
   double i;
   cin>>n>>x;

   if(n==x)
   {
     cout<<1;
   }

   else
   {
     i=ceil(n/2);
     in++;

     while(i!=x)
     {
       if(x>i)
       {
         i=ceil(i+(abs(oi-i))/2);
         in++;
       }
       else
       {
         oi=i;
         i=ceil(i/2);
         in++;
       }
     }
     cout<<in;
   }
 }
