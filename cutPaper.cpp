#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int width;
    int height;

    int times;
    int temp;
    int WHcheck;

    vector<int> widthVec;
    vector<int> heightVec;

    vector<int> pieceW;
    vector<int> pieceH;

    int maxW = -987654321;
    int maxH = -987654321;

    cin >> width;
    cin >> height;
    cin >> times;   // 몇번 자르냐

    

    for(int i=0;i<times;i++){
        cin >> WHcheck;
        cin >> temp;
        if(WHcheck)
        {
            widthVec.push_back(temp);
        }
        else if(WHcheck == 0)
        {
            heightVec.push_back(temp);
        }
    }
    sort(widthVec.begin(), widthVec.end());
    sort(heightVec.begin(), heightVec.end());

    widthVec.push_back(width);
    heightVec.push_back(height);

    for(int i=1;i<widthVec.size();i++)
    {
        pieceW.push_back(widthVec[i] - widthVec[i-1]);
    }
    pieceW.push_back(widthVec[0]);
    for(int i=1;i<heightVec.size();i++)
    {
        pieceH.push_back(heightVec[i] - heightVec[i-1]);
    }
    pieceH.push_back(heightVec[0]);

    for(int i=0;i<pieceW.size();i++)
    {
        maxW = ( maxW > pieceW[i]) ? maxW : pieceW[i];
    }
    for(int i=0;i<pieceH.size();i++)
    {
        maxH = ( maxH > pieceH[i]) ? maxH : pieceH[i];
    }

    cout << maxW * maxH << endl;
    
    return 0;
}