#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int a,b,p=1;
	cin>>a>>b;
	while(b!=0)
	{
		if(b%2==0)
		{
			b=b/2;
			a=a*a;
		}
		else
		{
		    p=p*a;	
			b--;
		}
	}
	cout<<p;
}
