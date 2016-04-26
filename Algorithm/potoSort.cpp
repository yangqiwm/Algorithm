// Algorithm.cpp : �������̨Ӧ�ó������ڵ㡣

/*Description:
*	the quesition is from <<�㷨�������ž���>> p110: TopoSort Quesition. 
*/
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

#define Max 1024

int G[Max][Max];
int vis[Max];
int d[Max], t;
int n,m;
bool dfs(int v)
{
	vis[v] = -1;
	for(int i=0;i<n;i++)
	{
		if(G[v][i]==1)
		{
			if(-1 == vis[i])
				return false;
			else
				if(vis[i] == 0 && dfs(i) == false)
					return false;
		}
	}
	vis[v] = 1;
	d[--t] = v;
	return true;
}

bool topo()
{
	for(int i=0;i<n;i++)
	{
		if(vis[i] == 0)
		{
			if(false == dfs(i))
				return false;
		}
	}
	return true;
}

int main()
{
	int m=0;
	cin>>n>>m;

	t = n;
	int x,y;
	for(int i=0;i<m;i++)
	{
		cin>>x>>y;
		G[x][y] = 1;
	}

	topo();
	for(int i=0;i<n;i++)
		cout<<d[i]<<endl;
	system("pause");
	return 0;
}

