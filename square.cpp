#include <iostream>
using namespace std;

class Point
{
public:
    int x;
    int y;

    Point(int _x, int _y):x(_x),y(_y) {}
    Point() : x(0), y(0) {}
};

class Square : public Point
{
public:
    Point leftlow;
    Point rightup;

    Square(Point &x, Point &y) : leftlow(x), rightup(y){}
    Square() : leftlow(0, 0), rightup(0, 0) {}
    void setSquare(int t1, int t2, int t3 ,int t4)
    {
        leftlow = Point(t1, t2);
        rightup = Point(t3, t4);
    }
};

int main()
{
    bool map[101][101] = {0, };
    Square sarr[4];
    int temp1, temp2, temp3, temp4;
    int cnt = 0;
    for(int i=0;i<4;i++)
    {
        cin >> temp1;
        cin >> temp2;
        cin >> temp3;
        cin >> temp4;
        sarr[i].setSquare(temp1, temp2, temp3, temp4);
    }

    for(int pt = 0; pt < 4; pt++)
    {
        for(int i=0;i<101;i++)
        {
            for(int j=0;j<101;j++)
            {
                if(sarr[pt].leftlow.x <= j && sarr[pt].rightup.x >j && sarr[pt].leftlow.y <= i && sarr[pt].rightup.y > i)
                {
                    map[i][j] = 1;
                }                
            }

        }
    }

    for(int i=0;i<101;i++)
    {
        for(int j=0;j<101;j++)
        {
            if(map[i][j])
                cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}