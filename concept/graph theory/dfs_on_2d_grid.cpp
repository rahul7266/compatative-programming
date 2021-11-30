#include<bits/stdc++.h>
using namespace std;
int m[100][100],
vis[100][100];
bool is_valid(int a,int b)
{
if(a>=5||b>=5||a<0||b<0||vis[a][b]==1)
	return false;
return true;	
}
void dfs(int x,int y)
{
	vis[x][y]=1;
	cout<<x<<" "<<y<<endl;
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
	int i,j;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		m[i][j]=1;
	}
	dfs(0,0);
}
