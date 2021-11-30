#include<bits/stdc++.h>
using namespace std;
#define inf 100000001
vector<pair<int ,int> > arr[10000];
int dist[10000]; 
int main()
{
	 int i,a,b,w,ver,e;
	 cin>>e>>ver;
	 for(i=0;i<e;i++)
	 {
	 	cin>>a>>b>>w;
	 	arr[a].push_back({b,w});
	 	arr[b].push_back({a,w});
	 }
	 for(i=0;i<=ver;i++)
	 dist[i]=inf;
	priority_queue <pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
	pq.push({0,1});
	dist[1]=0;
	while(!pq.empty())
	{
	int curr;
	int curr_d;	
	curr_d=pq.top().first;
	curr=pq.top().second;
	pq.pop();
	for(i=0;i<arr[curr].size();i++)
	{
		pair<int,int> child=arr[curr][i];
		if(dist[child.first]>child.second+curr_d)
		{
			dist[child.first]=child.second+curr_d;
			pq.push({dist[child.first],child.first});
			
		}
     } 
	}
	for(i=1;i<=ver;i++)
	cout<<dist[i]<<" ";
	
}

