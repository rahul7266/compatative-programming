#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> arr[10000];
	int a,b,i;
	for(i=0;i<4;i++)
	{
		cin>>a>>b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	
}
