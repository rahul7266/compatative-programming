#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int x,i,c=0;
	cin>>x;
	for(i=2;i*i<x;i++)
	{
		if(x%i==0)
		{
			c=0;
			while(x%i==0)
		{
			c++;
       	 	x=x/i;
		}
			cout<<i<<"^"<<c<<"*";
	   }
   }
	if(x>1)
	cout<<x<<"^"<<1<<endl;
}

