#include <stdio.h>
#define MAX 1000000

long long i,j,k=1,n,pflag[MAX];

int main()
{
	pflag[0] = pflag[1] = 1;
	
	for(i=2;i<=MAX;i++)
	{
		if(pflag[i] == 0)
		{
			printf("..%lld..\n",i);
			k++;
			for(j = i*i; j<= MAX; j+=i)
			{
				pflag[j] = 1;
				
			}
		}
	}
	
	for(i=2;i<=MAX;i++)
	{
		//if(pflag[i] == 1)
		//cout<<i<<endl;
	}
	printf("count: %lld\n",k);
}


