#include <stdio.h>

int main()
{
	char ch[10000][20],t[10000][20],a[10000][20];
	int i=0 ,j,count[100000]={0},k=0,b[100],m,n,l=0,x;
	
	printf("Enter paragraph: \n");
	
	//took input until ENTER is pressed
	for(;;)
   {
   	scanf("%s", &ch[i]);
   	if(getchar() == '\n') break;
   	i++;
   	k++;
   }
   
   /*For instance: Corona and Corona. are both same word but full stop(.) or other punctuations clings to such words make it different form other. To
   avoid this mistake we turn those pucntuations into null character so that compiler understand the end of the word and it will help to indentifying 
   similar words*/
   
   for(i=0;i<=k;i++)
	{
		for(j=0; ch[i][j] != '\0'; j++)
		{
			if((ch[i][j] == '.') || (ch[i][j] == '!') || (ch[i][j] == '?') || (ch[i][j] == ',') || (ch[i][j] == ':')|| (ch[i][j] == ';')|| (ch[i][j] == '-')
			|| (ch[i][j] == '_') || (ch[i][j] == '\'')|| (ch[i][j] == '(')|| (ch[i][j] == ')')|| (ch[i][j] == '{')|| (ch[i][j] == '}')
			|| (ch[i][j] == '[]')|| (ch[i][j] == ']')) 
			
			ch[i][j] = '\0';
		}
	}
	
	//Sorting the given strings alphabatically....
	
	for(i=0;i<=k;i++)		
       for(j=0;j<=k-1-i;j++)
           {
        if(strcmp(ch[j],ch[j+1])>0)
        {
            strcpy(t[i],ch[j]);
            strcpy(ch[j],ch[j+1]);
            strcpy(ch[j+1],t[i]);
        }
    }
    
    
    //Finding distinct strings from the paragraph.....
    
    for(i=0;i<k;i=j)
    {
    	for(j=i+1; j<(k+1); j++)
    	{
    		if(strcmp(ch[i],ch[j]) == 0) continue;
    		else
    		{
    			strcpy(a[l],ch[i]);
    			l++;
    			break;
			}
		}
	}
	strcpy(a[l],ch[i]);
    
    
    //counting mode using distinct strings.....
     for(i=0;i<=l;i++)
    {
    	for(j=0;j<=k;j++)
		{
    	if(strcmp(a[i],ch[j]) == 0)
		{
			count[i]++;
			b[i] = i;
		}	
		}
    	
	}
	
	
/* Frequencies of all DISTINCT members......(it can be used to asses whether the result accurate or not)
	
	
	for(i=0;i<=l;i++)
	printf("%s-->(%d)\n", a[i],count[i]);
	*/
    
    
    //sorting the frequencies of DISTINCT strings along with the indices.
    
    for(j=l;j>0;j--)		
	{
		for(i=0;i<j-1;i++)
		{
			if(count[i] < count [i+1])
			{
				m = count[i];
				n = b[i];
				count[i] = count[i+1];
				b[i] = b[i+1];
				count[i+1] = m;
				b[i+1] = n;
				
			}
		}
	}
	
/*	printf("------------Frquencies with sorted indices-----------------\n");
	for(i=0;i<=l;i++)	
	printf("--->%d\n", count[i]);*/
    
    
    printf("-------------------Paragraph Keyword-----------------\n");
	//we have used most common PREPOSiTIONS, CONJUNCTION and Verbs to avoid unwanted result.... 
	for(i=0,x=0;;i++)
	{
		if((strcmp(a[b[i]],"the") == 0) || (strcmp(a[b[i]],"a") == 0) ||(strcmp(a[b[i]],"an") == 0) ||(strcmp(a[b[i]],"to") == 0)||(strcmp(a[b[i]],"at") == 0)
		||(strcmp(a[b[i]],"on") == 0)||(strcmp(a[b[i]],"in") == 0)||(strcmp(a[b[i]],"of") == 0)||(strcmp(a[b[i]],"for") == 0)||(strcmp(a[b[i]],"over") == 0)
		||(strcmp(a[b[i]],"by") == 0)||(strcmp(a[b[i]],"but") == 0)||(strcmp(a[b[i]],"and") == 0)||(strcmp(a[b[i]],"or") == 0)||(strcmp(a[b[i]],"so") == 0)
		||(strcmp(a[b[i]],"as") == 0)||(strcmp(a[b[i]],"with") == 0)||(strcmp(a[b[i]],"up") == 0)||(strcmp(a[b[i]],"into") == 0)||(strcmp(a[b[i]],"without") == 0)
		||(strcmp(a[b[i]],"am") == 0)||(strcmp(a[b[i]],"is") == 0)||(strcmp(a[b[i]],"are") == 0)||(strcmp(a[b[i]],"were") == 0)||(strcmp(a[b[i]],"be") == 0)
		||(strcmp(a[b[i]],"been") == 0)||(strcmp(a[b[i]],"being") == 0)||(strcmp(a[b[i]],"has") == 0)||(strcmp(a[b[i]],"have") == 0)||(strcmp(a[b[i]],"had") == 0)
		||(strcmp(a[b[i]],"both") == 0)||(strcmp(a[b[i]],"however") == 0) ||(strcmp(a[b[i]],"from") == 0))
		continue;
		else
		{
			printf("%s\n", a[b[i]]);
			x++;
			if(x == 3) break;
		} 
		
	}
	
    

}
