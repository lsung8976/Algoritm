#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

int main()
{
    int size;
    int temp1, temp2;
    int max = INF * -1;
    int min = INF;
    int cnt =0;
    cin >> size;

    vector<vector<int>> vec2d(size, vector<int>(size, INF));
    vector<int> score(size);
    
    while(1)
    {
        cin >> temp1;
        cin >> temp2;
        temp1 -= 1;
        temp2 -= 1;
        if(temp1 == -2 && temp2 == -2) break;
        vec2d[temp1][temp2] = 1;
        vec2d[temp2][temp1] = 1;
    }

    //x=y 0으로 초기화
    for(int i=0;i<size;i++)
    {
        vec2d[i][i] = 0;
    }

    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            for(int k=0;k<size;k++)
            {
                vec2d[j][k] = (vec2d[j][k] > vec2d[j][i] + vec2d[i][k]) ? vec2d[j][i] + vec2d[i][k] : vec2d[j][k];
            }
        }
    }

    //score 정리
    for(int i=0;i<size;i++)
    {
        for(int j = 0;j<size;j++)
        {
            if(i == j) continue;
            max = (max < vec2d[i][j]) ? vec2d[i][j] : max;
        }
        score[i] = max;
        max = INF * -1;
    }
    /*
    //벡터 보여주기
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            cout << vec2d[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    */

    for(int i=0;i<score.size();i++)
    {
        min = (min < score[i]) ? min:score[i];
    }
    
    for(int i=0;i<score.size();i++)
    {
        if(min == score[i]) cnt++;
    }
    cout << min << " " << cnt << endl;
    
    for(int i=0;i<score.size();i++)
    {
        if(min == score[i]) cout << i + 1 << " ";
    }
    cout << endl;
    return 0;
}