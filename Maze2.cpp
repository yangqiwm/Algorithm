#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define Max 65535

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

int queue[Max];
int fa[11][11];
int dist[Max];
int vis[10][10];
int m=10;
int n=10;
char maze[11][11];

void bfs(int x,int y)
{
	memset(queue,0,sizeof(queue));
	memset((*fa),0,sizeof(fa));
	memset(dist,0,Max);
	memset((*vis),0,sizeof(vis));
	

    int front=0,rear=0;
    int u = x * m + y;
    
    queue[rear++] = u;
    vis[x][y] = 1;
    while(front < rear)
        {
        u = queue[front ++];
        
        for(int i=0;i<4;i++)
          {
        	int nx = u/m + dx[i], ny = u%m + dy[i];
            
            if(nx >=0 && nx <n && ny >=0 && ny <m && maze[nx][ny]=='.' && !vis[nx][ny])
                {
                int nu = nx * m + ny;
                queue[rear++] = nu;
                vis[nx][ny] = 1;
                fa[nx][ny] = u;
                dist[nu] = dist[u] + 1; 
                
            }
            
        }
        
    }
}

int main()
{
	while (cin >> maze[0][0])
    {
        for (int i = 0; i < 10; ++i)
            for (int j = 0; j < 10; ++j)
            {
                if (i == 0 && j == 0) continue;
                cin >> maze[i][j];
            }

	 bfs(0,1);
    int res = dist[9 * m +8];
    cout<<res<<endl;

    }

	system("pause");

	return 0;
}
