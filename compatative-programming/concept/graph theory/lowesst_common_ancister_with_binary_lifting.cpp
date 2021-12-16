#include<bits/stdc++.h>
using namespace std;
int vis[100000];
int s_m[101][101];
int dist[1000];
int max_n;
vector<int> arr[10000];
void dfs(int v,int p,int d)
{
	int i;
  	vis[v]=1;
  	s_m[v][0]=p;
  	dist[v]=d;
  	for(i=0;i<arr[v].size();i++)
  	{
  		int child=arr[v][i];
  	    if(vis[child]==0)	
  	    {
  	    	dfs(child,v,dist[v]+1);
		}
	}
}
int main()
{
	int e,ver,i,a,b,j,par,ta,tb,la,lb,t,d;
	cin>>e>>ver;
	for(i=0;i<=100;i++)
    {
    	for(j=0;j<=100;j++)
    	s_m[i][j]=-1;
	}
	for(i=0;i<e;i++)
	{
		cin>>a>>b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	cin>>ta>>tb;
    dfs(1,-1,0);
  
   max_n=log2(ver);
   for(j=1;j<=max_n;j++)
   {
   	for(i=1;i<=ver;i++)
   	{
        if(s_m[i][j-1]!=-1)
		{
	      par=s_m[i][j-1];
		  s_m[i][j]=s_m[par][j-1];		
	    }   	  	
	}
   }
    /*  for(i=0;i<=ver;i++)
    {
	for(j=0;j<=ver;j++)
    cout<<s_m[i][j]<<" ";
    cout<<endl;
   }
   for(i=1;i<=ver;i++)
   cout<<dist[i]<<" ";*/
   la=dist[ta];
   lb=dist[tb];
   if(la>lb)
   {
   	t=ta;
   	ta=tb;
   	tb=t;
   }
   
     d=dist[tb]-dist[ta];
 //  cout<<d<<" "<<tb<<endl;
   while(d>0)
   {
   	i=log2(d);
   	tb=s_m[tb][i];
   //	cout<<tb<<" ";
   	d-=1<<i;
   }
   //cout<<tb<<endl;
   if(ta==tb)
   cout<<tb;
   else
   {
   	for(i=max_n;i>=0;i--)
   	{
   		if(s_m[ta][i]!=-1&&(s_m[tb][i]!=s_m[ta][i]))
   		ta=s_m[ta][i],tb=s_m[tb][i];
	  
	}
	 cout<<s_m[ta][0];
   }

}

