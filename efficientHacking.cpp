#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> map; //맵
vector<bool> chkMap; //지나간자리 check
int cnt = 0 ;

int dfs(int node, int size)
{
    int hop = 0;
    while(!map[node].empty())
    {
        int smallNode = map[node].back(); map[node].pop_back();
        if(chkMap[smallNode] == false)
        {
            hop++;
            hop += dfs(smallNode, size);
            chkMap[smallNode] = true;
        }
    }
    return hop;
}

int main()
{  
    int n,m;
    int temp1 ,temp2;
    int max = -987654321;

    cin >> n;
    cin >> m;

    vector<int> fmap(n + 1);
    vector<int> hop(n + 1, 0);
    vector<bool> fchkMap(n+1,0);    //check 맵 초기화용
    
    map = fmap;
    chkMap = fchkMap;

    while(m--)
    {
        cin >> temp1 >> temp2;
        map[temp2].push_back(temp1);
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < map[i].size(); j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    
    /*
    for(int i=1;i<=n;i++)
    {
        hop[i] = dfs(i, n);
        chkMap = fchkMap;
    }

    for(int i=1;i<=n;i++)
    {
        max = (max > hop[i]) ? max : hop[i];
    }
    
    for(int i=1;i<=n;i++)
    {
        if(max == hop[i])
            cout << hop[i] << " ";
    }
    cout << endl;
    */

    return 0;
}