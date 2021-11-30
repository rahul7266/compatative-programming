#include<bits/stdc++.h>
using namespace std;
int vis[100000];
int dist[10000];
int par[100000];
vector <int> arr[100000];
void dfs(int v,int d)
{
	int i;
	vis[v]=1;
	dist[v]=d;
	for(i=0;i<arr[v].size();i++)
	{
		int child=arr[v][i];
		if(vis[child]==0)
		{
			par[child]=v;
			dfs(child,dist[v]+1);
		}
	}
}
int main()
{
	int i,ver,a,b,ta,tb,t,d,lca,ans,targeta,targetb;
	cin>>ver;
	for(i=0;i<ver-1;i++)
	{
		cin>>a>>b;
		arr[a].push_back(b);
		arr[b].push_back(b);
	}
	dfs(1,0);
	cin>>ta>>tb;
	targeta=ta;
	targetb=tb;
	par[1]=1;
    if(ta>tb)	
    {
    	t=ta;
    	ta=tb;
    	tb=t;
	}
	d=tb-ta;
	while(d!=0)
	{
		d--;
		tb=par[tb];
	}
//	for(i=1;i<=ver;i++)
//	cout<<par[i]<<" ";
	cout<<endl;
	if(ta==tb)
	lca=ta;
	else
	{
	while(par[ta]!=par[tb])
	{
		ta=par[ta];
		tb=par[tb];
	}
	lca=ta;	
	}
	ans=dist[targeta]+dist[targetb]-2*dist[lca];
	cout<<ans<<endl;
}
