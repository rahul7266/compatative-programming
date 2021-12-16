#include<bits/stdc++.h>
using namespace std;
int vis[1001];
int in[1001];
vector<int> res;
vector <int> arr[1001];
void kahns(int v)
{
	int i;
	queue<int> q;
	for(i=1;i<=v;i++)
	{
		if(in[i]==0)
		q.push(i);
	}
	while(!q.empty())
	{
		int curr=q.front();
		res.push_back(curr);
		q.pop();
		for(i=0;i<arr[curr].size();i++)
		{
			int child=arr[curr][i];
			in[child]--;
			if(in[child]==0)
			q.push(child);
		}
	}
	cout<<"topsort"<<endl;
	for(i=0;i<res.size();i++)
	cout<<res[i]<<" ";
	
}
int main()
{
   int a,b,v,e,i;
   cin>>v>>e;
   for(i=1;i<=e;i++)
   {
   	cin>>a>>b;
   	arr[a].push_back(b);
   	in[b]++;
   }
   kahns(v);
}
