#include<bits/stdc++.h>
using namespace std;
vector <int> arr[10000];
int vis[10000];
int dis[10000];
void bfs(int v,int d)
{
	int i;
	queue <int> q;
	q.push(v);
	vis[v]=1;
	dis[v]=d;
	while(!q.empty())
	{
		int node=q.front();
		for(i=0;i<arr[node].size();i++)
		{
			int child=arr[node][i];
			if(vis[child]==0)
			{
			q.push(child);
			vis[child]=1;
			dis[child]=dis[node]+1;
			}
		}
		cout<<node<<" "<<endl;
		q.pop();
	}
	
}
int main()
{
	int a,b,i,e,v;
	cin>>e>>v;
	for(i=0;i<e;i++)
   { 
    cin>>a>>b;
	arr[a].push_back(b);
	arr[b].push_back(a);
   }
   bfs(3,0);  
   
}
