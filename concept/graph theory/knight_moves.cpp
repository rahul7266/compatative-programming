//in distance mattrix we have to put no of moves it will take to move knight from one point on chess board to another
#include<bits/stdc++.h>
using namespace std;
int vis[10][10];
int dist[10][10];
int dy[]={1,2,2,1,-1,-2,-2,-1};
int dx[]={-2,-1,1,2,2,1,-1,-2};
int targetx;
int targety;
bool is_valid(int a,int b)
{
	if(a>8||a<1||b>8||b<1||vis[a][b]==1)
	return false;
	return true;
}
int bfs(int x,int y)
{
	int i;
	queue <pair<int,int> >q;
	dist[x][y]=0;
	vis[x][y]=1;
	q.push({x,y});
	if(x==targetx&&y==targety)
	return dist[x][y];
	while(!q.empty())
	{
		int currx=q.front().first;
		int curry=q.front().second;
		q.pop();
		for(i=0;i<8;i++)
		if(is_valid(currx+dx[i],curry+dy[i]))
		{
			int newx=currx+dx[i];
			int newy=curry+dy[i];
			dist[newx][newy]=dist[currx][curry]+1;
			vis[newx][newy]=1;
			q.push({newx,newy});
			if(newx==targetx&&newy==targety)
			return dist[newx][newy];
		}
	}
}
int main()
{
	int x,y,q;
	cin>>q;
	while(q--)
	{
		int i,j;
		char a,b,c,d;
		for(i=1;i<=8;i++)
		{
			for(j=1;j<=8;j++)
			vis[i][j]=0;
			dist[i][j]=0;
		}
		cin>>a>>b;//starting postion
		int x=a-'a'+1;
		int y=b-'0';
		cin>>c>>d; //end postion
		targetx=c-'a'+1;
		targety=d-'0';
		cout<<bfs(x,y)<<endl;
	}
}
