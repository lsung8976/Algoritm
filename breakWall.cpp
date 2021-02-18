#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

vector< vector<int> > map;

int main()
{
    string str;
    int height;
    int width;

    cin >> height;
    cin >> width;

    vector< vector<int> > fmap(height);

    for(int i=0;i < height;i++)
    {
        cin >> str;
        for(int j=0;j < width;j++)
        {
            fmap[i].push_back(static_cast<int>(str[j]) - '0');
        }
    }

    map = fmap;

    
    

    return 0;
}