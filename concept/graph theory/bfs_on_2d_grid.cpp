#include<bits/stdc++.h>
using namespace std;
int vis[100][100];
int m[100][100];
int dis[100][100];
queue < pair <int,int> > q;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
bool is_valid(int a,int b)
{
	if(a>=5||a<0||b>=5||b<0||vis[a][b]==1)
	return false;
	return true;
}
void bfs(int x,int y)
{
	int i;
	vis[x][y]=1;
	q.push({x,y});
	while(!q.empty())
	{
	
		int a=q.front().first;
		int b=q.front().second;
		q.pop();
		for(i=0;i<4;i++)
		{
			if(is_valid(a+dx[i],b+dy[i]))
			{
				int newx=a+dx[i];
				int newy=b+dy[i];
				dis[newx][newy]=dis[a][b]+1;
				vis[newx][newy]=1;	
				q.push({newx,newy});
			}
		}
	}
}
int main()
{
	int i,j;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		  cin>>m[i][j];
	}
	bfs(2,2);
		for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		  cout<<dis[i][j]<<" ";
		cout<<endl;  
    }
}
