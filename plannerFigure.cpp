#include <iostream>
#include <vector>
using namespace std;

vector< vector<int> > checkMap;
int p[12][2] = {{-1,-2},{0,-2},{1,-2},{2,-1},{2,0},{2,1},{1,2},{0,2},{-1,2},{-2,1},{-2,0},{-2,-1}};

int main()
{
    vector< vector<int> > fMap(6);
    int temp;
    int yesChk = 0;
    int noChk = 0;

    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            cin >> temp;
            fMap[i].push_back(temp);
        }
    }

    checkMap = fMap;
    
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            if(checkMap[i][j] != 0)
            {
                for(int k=0;k<12;i++)
                {
                    int nx = i + p[k][0];
                    int ny = j + p[k][1];
                    if(nx >= 0 && ny >= 0 && nx < 6 && ny < 6)
                    {
                        if(checkMap[nx][ny] != 0)
                        {
                            yesChk = 1;
                            break;
                        }
                    }
                }
                //break 구문 빠져나왔을때 마주보는면이 있는것 yesChk =1;
                //그냥 빠져나오면 noChk = 1 마주보는 면 없음
                if(yesChk == 1)
                {
                    yesChk = 0;
                    continue;
                }
                if(noChk == 1)
                {
                    break;
                }
            }
        }
        if(yesChk == 1)
        {
            
        }
        if(noChk == 1)
        {
            break;
        }
    }

    if(noChk == 1)
    {
        cout << "전개도 아님" << endl;
        return 0;
    }
    cout << "전개도 맞다" << endl;
    /*
    for(int i=0;i<6;i++)
    {
        for(int j= 0; j<6;j++)
        {
            cout << fMap[i][j] << " ";
        }
        cout << endl;
    }
    */

    return 0;
}