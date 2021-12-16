#include<bits/stdc++.h>
using namespace std;
vector <int> arr[1000000];
int vis[1000000];
int maxd,maxnode;
void dfs(int v,int d)
{
	vis[v]=1;
	int i;
	if(d > maxd)
	{
		maxd=d;
		maxnode=v;
	}
	for(i=0;i<arr[v].size();i++)
	{
		int child=arr[v][i];
		if(vis[child]==0)
		{
			dfs(child,d+1);
		}
	}
}
int main()
{
	int a,b,i,e,ver;
	cin>>e>>ver;
	for(i=0;i<e;i++)
	{
		cin>>a>>b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	maxd=-1;
	dfs(1,0);
	maxd=-1;
	for(i=0;i<=ver;i++)
	vis[i]=0;
	dfs(maxnode,0);
	cout<<maxd;
}
