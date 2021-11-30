#include<bits/stdc++.h>
using namespace std;
vector <int> arr[10000];
int vis[10000]={0};
void dfs(int v)
{
	int i;
	vis[v]=1;
	for(i=0;i<arr[v].size();i++)
	{
		int child=arr[v][i];
		if(vis[child]==0)
		dfs(child);
	}
}
int main()
{
	int i,a,b,e,ver,c=0;
	cin>>e>>ver;
	for(i=0;i<e;i++)
	{
		cin>>a>>b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	for(i=1;i<=ver;i++)
	{
		if(vis[i]==0)
		{
		dfs(i);
		c++;
	   }
	}
	cout<<c<<endl;
}
