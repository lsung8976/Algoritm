#include <iostream>
#include <vector>

using namespace std;

int visitNum = 0;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
vector< vector<int> > visited;

void bfs(int y, int x, int n) {
    if(visited[y][x] == 0)
    {
        visited[y][x] = visitNum;
        for(int i=0;i<4;i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(nx >= 1 && ny >= 1 && nx <= n && ny <= n)
                bfs(ny, nx, n);
        }
    }
    else return;
}

int main()
{
    int n;
    int lv = 0;
    int maxN = -100;
    cin >> n;

    vector<int> spaceNum(n + 1, 0);
    vector< vector<int> > inputVec(n + 1, vector<int> (n + 1, 0));
    vector< vector<int> > visitedTemp(n + 1, vector<int> (n + 1, 0));
    
    visited = visitedTemp;
    
    for(int i = 1;i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            scanf("%d", &inputVec[i][j]);
        }
    }
    
    while(lv <= 100)
    {
        for(int i = 1;i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(lv >= inputVec[i][j])
                    inputVec[i][j] = visited[i][j] = -1;
                else visited[i][j] = 0;
            }
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(visited[i][j] == 0) visitNum++;
                bfs(i,j, n);
            }
        }
        
        // for(int i=1;i<=n;i++)
        // {
        //     for(int j=1;j<=n;j++)
        //     {
        //         printf("%4d", visited[i][j]);
        //     }
        //     printf("\n");
        // }
        // printf("\n");

        maxN = (visitNum>maxN) ? visitNum : maxN;
        visitNum = 0;
        lv++;
        
    }


    // for(int i = 1;i <= n; i++)
    // {
    //     for(int j = 1; j <= n; j++)
    //     {
    //         printf("%4d", inputVec[i][j]);
    //     }
    //     printf("\n");
    // }

    printf("%d", maxN);

    return 0;
}

