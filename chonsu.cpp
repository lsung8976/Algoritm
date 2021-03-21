#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int num;    //총 인원수
    int a, b; // a 와 b
    int lineNum; // 관계 갯수
    int temp1, temp2;  //  입력 임시 변수;
    int cnt = 0;

    cin >> num;
    cin >> a >> b;
    cin >> lineNum;

    vector< vector<bool> > map (num + 1, vector<bool>(num + 1, 0)); //관계 기록 맵
    vector<int> chonmap (num + 1, 0);   //촌수 기록 맵

    for(int i=0;i<lineNum;i++)
    {
        cin >> temp1 >> temp2;
        map[temp1][temp2] = 1;
        map[temp2][temp1] = 1;
    }

    queue<int> q;

    q.push(a);

    while(!q.empty())
    {
        int x = q.front(); q.pop();
        for(int i=1;i<=num;i++)
        {  
            if(map[x][i] == 1 && chonmap[i] == 0)
            {
                q.push(i);
                chonmap[i] = chonmap[x] + 1;
            }
        }
    }
    for(int i=1;i<=num;i++)
    {
        chonmap[i] = (chonmap[i] == 0)? -1 : chonmap[i];
    }
    cout << chonmap[b] << endl;

    return 0;
}