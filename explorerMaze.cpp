//boj.kr/
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <utility>
using namespace std;

vector< vector<int> > maze; // 입력된 미로 벡터
vector< vector<int> > cntMaze;  // 거리를 적어놓은 미로 벡터
vector< pair<int, int> > check; // 그 정점을 탐색했는가?
int dirct[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
queue < pair<int ,int> > q; //큐
int cnt = 0;    // 거리 상수

bool checkMap(int x, int y)
{
    if(maze[x][y] == 1)
    {
        for(int i=0;i<check.size();i++)
        {
            if(check[i].first == x && check[i].second == y)
                return false;
        }
    }
    return true;
}

void go(int x, int y, int h, int w)
{
    check.push_back(make_pair(x, y));
    q.push(make_pair(x,y));
    while(!q.empty())
    {
        cnt++; // 거리 증가
        int px = q.front().first;
        int py = q.front().second;
        q.pop(); //한 정점에서 주변 정점 탐색이후 큐에있는 정점 정보 원소 제거
        for(int i=0; i < 4; i++)
        {
            int nx = px + dirct[i][0];
            int ny = py + dirct[i][1];
            if((nx >= 0) && (ny >= 0) && (nx < h) && (ny < w))
            {
                if(checkMap(nx, ny))
                {
                    cntMaze[nx][ny] = cnt;      //거리 기록
                    check.push_back(make_pair(nx,ny));  // 통과했다는 기록
                    q.push(make_pair(nx,ny));   //큐에 등록
                }
            }
        }
    }
}

int main()
{
    string temp;
    int height;
    int width;

    
    cin >> height;
    cin >> width;

    vector< vector<int> > mazeMap(height);

    for(int i = 0; i < height ; i++)
    {
        cin >> temp;
        for(int j = 0; j < width ; j++)
        {
            mazeMap[i].push_back(static_cast<int>(temp[j] - '0'));
        }
    }

    maze = mazeMap;
    cntMaze = mazeMap;
    go(0,0, height, width);

    //거리를 기록한 미로 벡터 출력
    for(int i = 0; i < height ; i++)
    {
        for(int j = 0; j < width ; j++)
        {
            cout << cntMaze[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}