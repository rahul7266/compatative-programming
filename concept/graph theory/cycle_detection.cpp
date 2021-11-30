#include<bits/stdc++.h>
using namespace std;
vector <int> arr[100000];
int vis[100000];
bool dfs(int v,int par)
{
	 int i;
	 vis[v]=1;
	 for(i=0;i<arr[v].size();i++)
	 {
	 	int child=arr[v][i];
	 	if(vis[child]==0)
	 	{
	 		if(dfs(child,v)==true)
	 		return true;
		}
		else
		{
			if(child!=par)
			return true;
		}
	 }
	 return false;
}
int main()
{
	int a,b,e,ver,i,f=0;
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
			if(dfs(1,0))
			{
			f=1;
			break;
		  }
		}
	}
	if(f)
	cout<<"cycle dectecded";
	else
	cout<<"no cycle dectecded";
}
