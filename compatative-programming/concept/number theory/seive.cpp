#include<bits/stdc++.h>
using namespace std;
long long int a[100001]={0};
void make()
{
long long int i;
long long int j;
a[0]=1;
a[1]=1;
for(i=2;i*i<=10000;i++)
{
	if(a[i]==1)
	continue;
	for(j=i*i;j<=10000;j=j+i)
	a[j]=1;
}
}
int main()
{	
make();
}
