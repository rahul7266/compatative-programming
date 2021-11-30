#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int a,long long int b)
{
	if(b==0)
	return a;
	else
	{
		gcd(b,a%b);
	}
}
int main()
{
	long long int a,b,c;
	cin>>a>>b;
	c=gcd(a,b);
	cout<<c<<endl;
}
