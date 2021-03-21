#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector< vector<int> > map;
queue<int> q;

bool go(int node, int size, vector<bool>& chk)
{
    if(node == 0) return 0;

    chk[node] = true;
    cout << node << " ";
    
    for(int i = 0;i <= size; i++)
    {
       if(map[node][i] == 1 && chk[i] == false)
       {
           go(i, size, chk);
       }
    }
    return 0;

}

int main()
{
    
    int N;  //정점 갯수
    int M;  //간선 갯수
    int V;
    
    int N1; //정점입력1
    int N2; //정점입력2

    cin >> N;
    cin >> M;
    cin >> V;   //탐색을 시작할 곳

    vector< vector<int> > fmap(N + 1, vector<int> (N + 1, 0));
    vector<bool> chk(N+1, false);
    map = fmap;

    while(M--)
    {
        cin >> N1;
        cin >> N2;
        map[N1][N2] = map[N2][N1] = 1;
    }

    //BFS
    go(V, N, chk);
    cout << endl;

    //check배열 초기화
    for(int i = 0; i <= N;i++)
    {
        chk[i] = 0;
    }

    //DFS
    chk[V] = true;
    q.push(V);
    while(!q.empty())
    {
        int node = q.front(); q.pop();

        cout << node << " ";

        for(int i=0;i <= N;i++)
        {
            if(map[node][i] == 1 && chk[i] == false)
            {
                chk[i] = true;
                q.push(i);
            }
        }
    }

    cout << endl;
    
    return 0;
}