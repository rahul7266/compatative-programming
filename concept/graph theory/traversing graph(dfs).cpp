#include<bits/stdc++.h>
using namespace std;
int vis[1000]={0};
vector<int> arr[10000];
void dfs(int v)
{
    vis[v]=1;
	cout<<v;
	for(int i=0;i<arr[v].size();i++)
	{
	int child=arr[v][i];	
	if(vis[child]==0)
	dfs(child);
    }
}
int main()

{

	int a,b,i;
	for(i=0;i<4;i++)
	{
		cin>>a>>b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	dfs(1);
}
