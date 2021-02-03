#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector< vector<char> > map;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1 ,0, 0};
int g_width;
int g_height;

int waterCnt = 0;
int runnerCnt = "1";

void flood(int x, int y)
{   
    map[x][y] = waterCnt++;
    for(int i=0;i<4;i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(map[nx][ny] != 'X' && nx >= 0 && ny >= 0 && nx <= g_height && ny <= g_width)
        {
            flood(nx, ny);
        }
    }
    
}

int main()
{
    int width;
    int height;
    char temp;

    cin >> height; 
    cin >> width;
    g_height = height;
    g_width = width;

    vector< vector<char> > funcMap(height);

    for(int i=0;i<height ;i++)
    {
        for(int j=0;j<width; j++)
        {
            cin >> temp;
            funcMap[i].push_back(temp);
        }
    }

    map = funcMap;


    

    return 0;
}