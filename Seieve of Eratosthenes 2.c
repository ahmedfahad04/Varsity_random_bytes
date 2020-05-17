#include <stdio.h>
int prime (long long n)
{
   long long i, flag=0;
    for(i=2;i*i<=n;i++)
    { if(n%i==0)
    { flag=1;
    break;
    }
    }
    if (flag==0)
    return 1;
    else return 0;
}
int main ()
{ long long n,x,k,count=0,p;
scanf("%lli",&n);

if(n%2==0) printf("%lli",n/2);
else if(prime(n)) printf("1");

 else
    {
        	for(k = 3; k<10000000010; k++)
		{
			if(n%k == 0)
			{
				x = n-k;
				printf("%lld",1+x/2);
				break;
			}
			
		}

}
}
