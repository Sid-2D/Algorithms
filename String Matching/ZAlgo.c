#include<stdio.h>
typedef long long int lld;
lld get(char s[])
{
	lld len=0;
	do
	{
		s[len]=getchar();
	}while(s[len++]!='\n');
	s[--len]='\0';
	return len;
}
int main()
{
	lld q,i,len,l=0,r=0,p,ans,*z,k;
	z=(lld *)calloc(5000005,sizeof(lld));
	char *s=(char*)malloc(sizeof(char)*5000005);
	len=get(s);
	for(i=1;i<len;i++)
	{
		if(i>r)
		{
			l=r=i;
			while(r<len && s[r-l]==s[r])
				r++;
			r--;
			z[i]=r-l+1;
		}
		else
		{
			k=i-l;
			if(z[k]<r-i+1)
				z[i]=z[k];
			else
			{
				l=i;
				while(r<len && s[r-l]==s[r])
					r++;
				r--;
				z[i]=r-l+1;
			}
		}
	}
	scanf("%lld",&q);
	while(q--)
	{
		scanf("%lld",&p);
		if(z[p]<=p)
			printf("%lld\n",z[p]);
		else
			printf("%lld\n",p);
	}
	return 0;
}