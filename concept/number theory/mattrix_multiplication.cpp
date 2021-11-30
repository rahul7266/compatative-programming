#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int A[100][100],B[100][100],C[100][100],i,j,k,a,b,c,d,s=0;
	cin>>a>>b;
	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		cin>>A[i][j];
	}
	cin>>c>>d;
	for(i=0;i<c;i++)
	{
		for(j=0;j<d;j++)
		cin>>B[i][j];
	}	
	if(b!=c)
	cout<<"cannot be multiplied"<<endl;
	else
	{
		for(i=0;i<a;i++)
		{
		
			for(j=0;j<d;j++)
			{
				s=0;
				for(k=0;k<b;k++)
			      	s=s+A[i][k]*B[k][j];
				C[i][j]=s;
			}
		}
		for(i=0;i<a;i++)
		{
			for(j=0;j<b;j++)
			{
				cout<<C[i][j]<<" ";
			}
			cout<<endl;
		}
	}
}
