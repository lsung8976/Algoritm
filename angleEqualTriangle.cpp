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
    int getX() const
    {
        return x;
    }

    int getY() const
    {
        return y;
    }

    
};

bool map[10][10] = 
{   
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};


int nearbycnt(int x, int y)
{
    int cnt = 0;
    
    if(map[x-1][y] == 0) cnt++;
    if(map[x+1][y] == 0) cnt++;
    if(map[x][y-1] == 0) cnt++;
    if(map[x][y+1] == 0) cnt++;
    return cnt;
}

int main()
{
    vector<Point> picked;
    int sideLengthexpo[3];
    int chk = 0;
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
                    picked.push_back(Point(i + 1 ,j + 1));
                }
            }
        }
    }

    if(picked.size() == 3)
    {
        sideLengthexpo[0] = (picked[0].getX() - picked[1].getX()) * (picked[0].getX() - picked[1].getX()) + (picked[0].getY() - picked[1].getY()) * (picked[0].getY() - picked[1].getY());
        sideLengthexpo[1] = (picked[1].getX() - picked[2].getX()) * (picked[1].getX() - picked[2].getX()) + (picked[1].getY() - picked[2].getY()) * (picked[1].getY() - picked[2].getY());
        sideLengthexpo[2] = (picked[0].getX() - picked[2].getX()) * (picked[0].getX() - picked[2].getX()) + (picked[0].getY() - picked[2].getY()) * (picked[0].getY() - picked[2].getY());

        if(sideLengthexpo[0] == sideLengthexpo[1])
            if(sideLengthexpo[0] * 2 == sideLengthexpo[2])  chk = 1;
        if(sideLengthexpo[2] == sideLengthexpo[1])
            if(sideLengthexpo[2] * 2 == sideLengthexpo[0])  chk = 1;
        if(sideLengthexpo[0] == sideLengthexpo[2])
            if(sideLengthexpo[0] * 2 == sideLengthexpo[1])  chk = 1;

        if(chk)
        {
            for(int i = 0 ; i < picked.size() ; i++)
            {
                cout << picked[i].getX() << " " << picked[i].getY() << endl;
            }
        }
    }
    
    return 0;
}