#include <stdio.h>
int main()
{
    int i,n[150],x,p[150],c[150],k=0,l=0,j;
    
    for(i=0;i<100;i++)
   n[i] = i+1;
   
    
    for(i=1;i<100;i++)
    for(j=2;j<=n[i];j++)
    {
        if((n[i]%j == 0) && (n[i] == j))
       {
                p[k] = n[i];
                k++;
           		 break;
        }
        else if((n[i]%j == 0) && !(n[i] == j))
        {
           c[l] = n[i];
           l++;
         	break;
        }
        
    }
  
    
   for(i=0;i<k;i++)
    {
        printf("Prime: %d\n", p[i]);
    }
    
    
    for(i=0;i<l;i++)
    {
        printf("\t\tGeneral: %d\n", c[i]);
    }
}
