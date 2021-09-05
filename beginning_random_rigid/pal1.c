#include<stdio.h>
int rev(int r);
int add(int s, int t);
int process(int p);
int main()
{
    int n,count=0,b;
    scanf("%d",&n);

    while(n!=rev(n))
    {
        b=process(n);
        n=b;
        count++;
    }
    printf("\nThis is palindrome.\n");

    printf("After adding %d times, it becomes palindrome.\n",count);
}
int rev(int r)
{
    int reverse=0;
    while(r!=0)
    {
        reverse=reverse*10;
        reverse=reverse+r%10;
        r=r/10;
    }
    return reverse;
}
int add(int s,int t)
{
    int total;
    total=s+t;
    return total;
}
int process(int p)
{
    int b;

    printf("\nn=%d\n",p);
    rev(p);
    printf("reverse n=%d\n",rev(p));
    if(p==rev(p))
    {
        printf("This is palindrome\n");
    }
    else
    {
        printf("This is not palindrome\n");
        b=add(p,rev(p));
        printf("sum is %d\n",b);
    }
    return b;
}
