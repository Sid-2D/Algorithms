// Link: https://www.hackerrank.com/challenges/maxsubarray/problem

#include <stdio.h>
long int max(long int x,long int y)
{
	return (x>=y?x:y);
}
long int max1(long int x,long int y,long int z)
{
	if(x>=y)
    {
        if(x>=z)
			return x;
		else
			return z;
    }
	else
        {
		  if(y>=x)
              {
		  	   if(y>=z)
		  		  return y;
			   else
				  return z;
              }
        }
    return 0;
}
int main() 
{
	long int t,n,a[100005],i,sum,csum,cursum,j;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%ld",&a[i]);
		}
		csum=cursum=sum=a[0];
		for(j=1;j<n;j++)
		{
			cursum=max(a[j],cursum+a[j]);
			if(cursum>sum)
				sum=cursum;
			csum=max1(csum,csum+a[j],a[j]);
		}
		printf("%ld %ld\n",sum,csum);
	}
	return 0;
}
