//boj.kr/13549
#include <iostream>
#include <deque>
#include <vector>
#define MAX 100001

using namespace std;

deque<int> q;
vector<bool> chkVec(100001, 0);
vector<int> dist(100001 , 0);

int go(int n, int k)
{
    while(!q.empty())
    {
        int now = q.front(); q.pop_front();
        if(now + 1 < MAX)
        {
            if(chkVec[now + 1] == false)
            {
                q.push_back(now + 1); 
                dist[now + 1] = dist[now] + 1;
                chkVec[now + 1] = true;
            }
        }
        if(now - 1 >= 0)
        {
            if(chkVec[now - 1] == false)
            {
                q.push_back(now - 1);
                dist[now - 1] = dist[now] + 1;    
                chkVec[now - 1] = true;
            }
        }
        if(now * 2 < MAX)
        {
            if(chkVec[now * 2] == false)   
            {
                q.push_front(now * 2);
                dist[now * 2] = dist[now];
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
    q.push_front(N);

    cout << go(N, K) << endl;
    
    return 0;
}