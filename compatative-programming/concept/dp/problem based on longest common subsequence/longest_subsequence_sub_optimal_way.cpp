//return length of longest common sub sequence
#include<bits/stdc++.h>
using namespace std;
int sub(string s1,string s2,int n,int m)
{
 if(n==0||m==0)
 return 0;	
 if(s1[n-1]==s2[m-1])
 return sub(s1,s2,n-1,m-1)+1;
 else
 return max(sub(s1,s2,n-1,m),sub(s1,s2,n,m-1));	
}
int main()
{
	string s1,s2;
	int ans;
	cin>>s1>>s2;
	ans=sub(s1,s2,s1.size(),s2.size());
	cout<<ans<<endl;
}
