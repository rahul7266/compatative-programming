//one in  mattrix(in question) mean that room can be visited and 0 mean it can not be
#include<bits/stdc++.h>
using namespace std;
int m[100][100];
int vis[100][100];
bool is_valid(int a,int b)
{
	if(a>=5||a<0||b>=5||b<0||vis[a][b]==1||m[a][b]==0)
	return false;
	return true;
}
void dfs(int x,int y)
{
	vis[x][y]=1;
	if(is_valid(x,y+1))
	dfs(x,y+1);
	if(is_valid(x+1,y))
	dfs(x+1,y);
	if(is_valid(x,y-1))
	dfs(x,y-1);
	if(is_valid(x-1,y))
	dfs(x-1,y);
}
int main()
{
	int i,j,c=0;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		cin>>m[i][j];
	}
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(vis[i][j]==0&&m[i][j]!=0)
			{
				dfs(i,j);
				c++;
				
			}
		}
	}

	cout<<c<<endl;
	
}
