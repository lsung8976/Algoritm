#include <iostream>
#include <vector>
using namespace std;

int dE[3] = {-1, 0, 1};

int main()
{
    int velocity = 0;
    int x, y;
    int pos = x;

    vector <int> map (y, 0);

    while(pos == y)
    {
        for(int i=0;i<3;i++)
        {
            int engin = pos + velocity + dE[i];
            if(x < engin && engin <= y)
                map[nx] = 1;
            else
                map[nx] = 0;
        }
    }
    return 0;
}