//boj.kr/14226
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>

#define MAX 1001
using namespace std;


int countVec[MAX][MAX];
bool visitVec[MAX][MAX];
memset(countVec, -1, sizeof(MAX));
//memset(visitVec, false, sizeof(MAX))
queue< pair<int, int> > q;

int clipboard = 0;

int go(int s)
{
    int min = 987654321;
    while(!q.empty())
    {  
        pair<int, int> now = q.front(); q.pop();
        //now.first = "screen imoticon"
        //now.second = "clipboard imoticon"
        if(now.first < MAX)   //이모티콘 복사 하는경우
        {
            if(visitVec[now.first][now.second + now.first] == false)
            {
                countVec[now.first][now.second + now.first] = countVec[now.first][now.second] + 1;
                q.push(make_pair(now.first, now.second + now.first));
                visitVec[now.first][now.second + now.first] = true;
            }
        }

        if(now.first < MAX)   //이모티콘 붙여넣기 하는 경우
        {
            if(visitVec[now.first + now.second][now.second] == false) 
            {
                countVec[now.first + now.second][now.second] = countVec[now.first][now.second] + 1;
                q.push(make_pair(now.first + now.second, now.second));
                visitVec[now.first + now.second][now.second] = true;
            }
        }

        if(now.first > 0)     //이모티콘 삭제하는경우
        {
            if(visitVec[now.first - 1][now.second] == false) 
            {
                countVec[now.first - 1][now.second] = countVec[now.first][now.second] + 1;
                q.push(make_pair(now.first - 1, now.second));
                visitVec[now.first - 1][now.second] = true;
            }
        }
    }
    for(int i=0;i<MAX;i++)
    {
        if(visitVec[s][i] == true)
        {
            min = (min > countVec[s][i]) ? countVec[s][i] : min;
        }
    }
    return min;
}

int main()
{
    int S;
    cin >> S;
    q.push(1, 0);
    countVec[1][0] = 0;

    cout << go(S) << endl;
    for(int i=0;i<MAX;i++)
        cout << i << " : " << countVec[i] << endl;
    return 0;
}