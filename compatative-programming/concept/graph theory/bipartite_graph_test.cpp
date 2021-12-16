#include<bits/stdc++.h>
using namespace std;
vector <int> arr[10000];
int vis[100000];
int col[10000];//col is for color
bool dfs(int v,int c)
{
	int i;
	vis[v]=1;
	col[v]=c;
	for(i=0;i<arr[v].size();i++)
	{
		int child=arr[v][i];
		if(vis[child]==0)
		{
			if(dfs(child,c^1)==false)
			return false;
		}
		else
		{
			if(col[v]==col[child])
			return false;
		}
	}
	return true;
}
int main()
{
	int i,a,b,e,ver;
	cin>>e>>ver;
	for(i=0;i<e;i++)
	{
		cin>>a>>b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	if(dfs(1,0))
	cout<<"it is bipeptite"<<endl;
	else
	cout<<"it is not bipeptite"<<endl;
}
