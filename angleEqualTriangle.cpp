#include <iostream>
#include <vector>
using namespace std;

class Point
{
    int x;
    int y;
public:
    Point(int _x, int _y) : x(_x), y(_y) {}
    Point() : x(0), y(0) {}
    void setPoint(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
    void printPoint() const
    {
        cout << x << ", " << y << endl;
    }
};

bool map[10][10] = 
{   
    {0, 0, 0, 0, 0 ,0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int nearbycnt(int x, int y)
{
    int cnt;
    if(map[x-1][y] == 0) cnt++;
    if(map[x+1][y] == 0) cnt++;
    if(map[x][y-1] == 0) cnt++;
    if(map[x][y+1] == 0) cnt++;
    return cnt;
}

int main()
{
    vector<Point> picked;
    /*
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            cin >> map[i][j];
        }
    }
*/
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(map[i][j] == 1)
            {
                if(nearbycnt(i,j) == 3)
                {
                    picked.push_back(Point(i,j));
                }
            }
        }
    }

    for(int i=0;i<picked.size(); i++)
    {
        picked[i].printPoint();
    }

    return 0;
}