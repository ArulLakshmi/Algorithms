#include<stdio.h>

//q1..
void append(char s1[],char s2[])
{
	    char s[50];
	   	int i=strlen(s1)-strlen(s2);
	   	int j=0,k;
	   	k=i;
	   	while(i!=0)
		{
		    s[j]=0;
			i--;
			j++;
		}
		while(j<strlen(s2)+k && i<strlen(s2))
		{
			s[j]=s2[i];
			i++;j++;
		}
		strcpy(s2,s);

}
if(strlen(s2)<strlen(s1))
	     	
		append(s1,s2);

	   else if(strlen(s1)<strlen(s2))
	   	   	append(s2,s1);
	  

