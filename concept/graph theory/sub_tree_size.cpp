#include<bits/stdc++.h>
using namespace std;
vector <int> arr[1000];
int vis[10000];
int sub[10000];
int dfs(int v)
{
	int curr_size,i;
	vis[v]=1;
	curr_size=1;
	for(i=0;i<arr[v].size();i++)
	{
		int child=arr[v][i];
		if(vis[child]==0)
		{
			curr_size+=dfs(child);
		}
	}
	sub[v]=curr_size;
	return curr_size;
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
	dfs(1);
	for(i=1;i<=ver;i++)
	{
		cout<<sub[i]<<endl;
	}
}
