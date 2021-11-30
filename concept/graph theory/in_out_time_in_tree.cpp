#include<bits/stdc++.h>
using namespace std;
vector <int> arr[1000];
int in[100000];
int out[10000];
int vis[10000];
int timer=0;
void dfs(int v)
{
	vis[v]=1;
	int i;
	in[v]=timer++;
	for(i=0;i<arr[v].size();i++)
	{
		int child=arr[v][i];
		if(vis[child]==0)
		{
			dfs(child);
		}
	}
	out[v]=timer++;
}
int main()
{
	int a,b,e,ver,i;
	cin>>e>>ver;
	for(i=0;i<e;i++)
	{
		cin>>a>>b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	dfs(1);
	for(i=1;i<=ver;i++)
	{
		cout<<in[i]<<" "<<out[i]<<endl;
	}
}
