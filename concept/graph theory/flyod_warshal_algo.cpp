#include<bits/stdc++.h>
#define inf 100000 
using namespace std;
int graph[101][101];
int main()
{
	 int i,j,k;
	 for(i=1;i<=100;i++)
	 {
	 	for(j=1;j<=100;j++)
	 	{
	 	graph[i][j]=inf;	
		}
	 }
	 int w,a,b,e,ver;
	 cin>>e>>ver;
	 for(i=1;i<=e;i++)
	 {
	 	cin>>a>>b>>w;
	 	graph[a][b]=w;
	 }
	 for(i=1;i<=ver;i++)
	 {
	 	graph[i][i]=0;
	 }
	 for(k=1;k<=ver;k++)
	 {
	 	for(i=1;i<=ver;i++)
	 	{
	 		for(j=1;j<=ver;j++)
	 		{
	 		   if(graph[i][k]==inf||graph[k][j]==inf)
	 		   continue;
	 		   graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);	
			}
		 }
	 }
	 for(i=1;i<=ver;i++)
	 {
	 	for(j=1;j<=ver;j++)
	 	cout<<graph[i][j]<<" ";
		 cout<<endl; 
	 }
}
