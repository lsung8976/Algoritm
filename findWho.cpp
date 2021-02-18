//boj.kr/1697
#include <iostream>
#include <queue>
#include <vector>
#define MAX 100001

using namespace std;

queue<int> q;
vector<bool> chkVec(100001, 0);
vector<int> dist(100001 , 0);

int go(int n, int k)
{
    while(!q.empty())
    {
        int now = q.front(); q.pop();
        if(now + 1 < MAX)
        {
            if(chkVec[now + 1] == false)
            {
                q.push(now + 1); 
                dist[now + 1] = dist[now] + 1;
                chkVec[now + 1] = true;
            }
        }
        if(now - 1 >= 0)
        {
            if(chkVec[now - 1] == false)
            {
                q.push(now - 1);
                dist[now - 1] = dist[now] + 1;    
                chkVec[now - 1] = true;
            }
        }
        if(now * 2 < MAX)
        {
            if(chkVec[now * 2] == false)   
            {
                q.push(now * 2);
                dist[now * 2] = dist[now] + 1;
                chkVec[now * 2] = true;
            }
        }
    }

    return dist[k];
}

int main()
{
    int N;  //현재 위치
    int K;  //도착점


    cin >> N;
    cin >> K;

    dist[N] = 0;
    chkVec[N] = true;
    q.push(N);

    cout << go(N, K) << endl;
    for (int i=0;i<40;i++)
    {
        cout << i << " : " << dist[i] << endl;
    }
    cout << endl;
    return 0;
}