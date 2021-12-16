#include <bits/stdc++.h>
using namespace std;
struct edge{
    int a;
    int b;
    int wt;
};
bool comp(edge a,edge b)
{
    if(a.wt<b.wt)
    return true;
    
    return false;
}
edge ed[10001];
int par[10001];
int find(int a)
{
    if(par[a]==-1)return a;
    else 
    return par[a]=find(par[a]);
    
}
void uni(int a,int b)
{
    par[a]=b;
}
int main()
{
    
    
    int v,e,i,s=0;
    cin>>v>>e;
    for(i=0;i<e;i++)
    {
        cin>>ed[i].a>>ed[i].b>>ed[i].wt;   
    }
    sort(ed,ed+e,comp);
    for(i=1;i<=v;i++)
    par[i]=-1;
    for(i=0;i<e;i++)
    {
        int c,d;
        c=find(ed[i].a);
        d=find(ed[i].b);
        if(c!=d)
       { 
          
           s+=ed[i].wt;
            uni(c,d);
       }
    }
  
    cout<<s<<endl;
}

