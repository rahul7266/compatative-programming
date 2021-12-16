//disclamer this code only works on non cyclic graph(tree)
#include<bits/stdc++.h>
using namespace std;
int vis[1000]={0};
int dis[1000]={0};
vector<int> arr[10000];
void dfs(int v,int d)
{
    vis[v]=1;
    dis[v]=d;
	for(int i=0;i<arr[v].size();i++)
	{
	int child=arr[v][i];	
	if(vis[child]==0)
	dfs(child,dis[v]+1);
    }
}
int main()

{

	int a,b,i;
	for(i=0;i<5;i++)
	{
		cin>>a>>b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	dfs(1,0);
	for(i=1;i<=6;i++)
	cout<<dis[i]<<endl;
}
