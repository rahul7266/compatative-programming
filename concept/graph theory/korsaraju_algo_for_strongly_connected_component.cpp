#include<bits/stdc++.h>
using namespace std;
vector<int> arr[1001];
vector<int> trans[1001];
int vis[1000];
vector<int> order;
vector<int> scc;
void dfs(int v)
{
	vis[v]=1;
	int i;
	for(i=0;i<arr[v].size();i++)
	{
		int child=arr[v][i];
		if(vis[child]==0)
		dfs(child);
	}
	order.push_back(v);
}
void dfs1(int v)
{
	vis[v]=1;
	int i;
	for(i=0;i<trans[v].size();i++)
	{
		int child=trans[v][i];
		if(vis[child]==0)
		dfs1(child);
	}
	scc.push_back(v);
}
int main()
{
	int e,v,i,a,b,j,k=0;
	cin>>e>>v;
	for(i=0;i<e;i++)
	{
		cin>>a>>b;
		arr[a].push_back(b);
		trans[b].push_back(a);
	}
	for(i=1;i<=v;i++)
	{
		if(vis[i]==0)
		dfs(i);
	}
	for(i=1;i<=v;i++)
	vis[i]=0;
	for(i=0;i<order.size();i++)
	{
		
		if(vis[order[order.size()-i-1]]==0)
		{
		k++;
		scc.clear();
		dfs1(order[order.size()-i-1]);
	    cout<<k<<"st conected component "<<endl;
	    for(j=0;j<scc.size();j++)
	    {
	    	cout<<scc[j]<<endl;;
		}
	}
}
}
