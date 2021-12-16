#include<bits/stdc++.h>
using namespace std;
vector <int> arr[1000];
int vis[1000];
int in[100000];
int low[1000];
int cut_ver[10000];
int timer=0;
void dfs(int node,int par)
{
int children=0;
vis[node]=1;
in[node]=timer;
low[node]=timer;
timer++;
int i;
for(i=0;i<arr[node].size();i++)
{
	int child=arr[node][i];
	if(child==par)
	continue;
	if(vis[child]==1)
	{
		low[node]=min(low[node],in[child]);
	}
	if(vis[child]==0)
	{
    children++;
	dfs(child,node);
	if(low[child]>=in[node]&&par!=-1)	
	cut_ver[node]=1;
	low[node]=min(low[node],low[child]);
	}
	if(par==-1&&children>1)
	cut_ver[node]=1;
}
}
int main()
{
	int i,a,b,e,v;
	cin>>e>>v;
	for(i=0;i<e;i++)
	{
		cin>>a>>b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	dfs(1,-1);
	for(i=1;i<=v;i++)
	{
		if(cut_ver[i])
		cout<<i<<" is a cut vertex"<<endl;
	}
}
