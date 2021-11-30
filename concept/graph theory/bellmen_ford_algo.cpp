#include<bits/stdc++.h>
#define inf 100000000
struct edge
{
int a;
int b;
int w;	
};
using namespace std;
int dist[100000];
int main()
{
	int e,ver,i,j,flag=1;;
	cin>>e>>ver;
	edge ed[10000];
	for(i=0;i<e;i++)
	{
		cin>>ed[i].a;
		cin>>ed[i].b;
		cin>>ed[i].w;
	}
	for(i=1;i<=ver;i++)
	dist[i]=inf;
	dist[1]=0;
	for(i=0;i<ver-1;i++)
	{
		for(j=0;j<e;j++)
		{
			int cur_ver=ed[j].a;
			int next_ver=ed[j].b;
			if(dist[cur_ver]!=inf)
			{
				if(dist[cur_ver]+ed[j].w<dist[next_ver])
				dist[next_ver]=dist[cur_ver]+ed[j].w;
			}
		}
	}
		for(j=0;j<e;j++)
		{
			int cur_ver=ed[j].a;
			int next_ver=ed[j].b;
			if(dist[cur_ver]!=inf)
			{
				if(dist[cur_ver]+ed[j].w<dist[next_ver])
				{
					dist[next_ver]=dist[cur_ver]+ed[j].w;
					flag=0;
				}
			}
		}
		if(flag==0)
		cout<<"not possible to calculte min distance"<<endl;	
		else
		{
			for(i=1;i<=ver;i++)
			cout<<dist[i]<<" ";
		}
}
