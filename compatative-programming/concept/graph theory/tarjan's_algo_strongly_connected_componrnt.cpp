#include<bits/stdc++.h>
using namespace std;
int vis[1001];
int in[1001];
int low[1001];
int timer;
stack <int> s;
int scc;
int onstack[1001];
vector<int> arr[1001];
void dfs(int node)
{
	int i;
	timer++;
	vis[node]=1;
	onstack[node]=1;
	s.push(node);
	in[node]=timer;
	low[node]=timer;
	timer++;
	for(i=0;i<arr[node].size();i++)
	{
		int child =arr[node][i];
		if(vis[child]==1&&onstack[child]==1)
		{
			low[node]=min(in[child],low[node]);
		}
		else if(vis[child]==0)
		{
			dfs(child);
		    if(onstack[child]==1)
			low[node]=min(low[child],low[node]);
		}
		
	}
	if(in[node]==low[node])
	{
		scc++;
		cout<<"scc# "<<scc<<endl;
	    int x;
	    while(1)
	    {
	    	x=s.top();
	    	s.pop();
	    	onstack[x]=0;
	    	cout<<x<<" "<<endl;
	    	if(x==node)
	    	break;
		}
	
	}
}
int main()
{
	int e,v,i,a,b;
	cin>>e>>v;
	for(i=0;i<e;i++)
	{
		cin>>a>>b;
		arr[a].push_back(b);
	}
	for(i=1;i<=v;i++)
	{
	vis[i]=onstack[i]=0;	
	}
	for(i=1;i<=v;i++)
	{
	if(vis[i]==0) 
	dfs(i);
   }
}
