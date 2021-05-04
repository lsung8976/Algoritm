#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector< vector<int> > map; //맵
vector<bool> chkMap; //지나간자리 check
vector<int> ans;
int cnt = 0 ;

void dfs(int node)
{
    chkMap[node] = true;

    for(int i = 0;i < map[node].size(); i++)
    {
        int smallNode = map[node][i];
        if(chkMap[smallNode] == false)
        {
            cnt++;
            dfs(smallNode);
        }
    }
    return;
}

int main()
{  
    int n,m;
    int temp1 ,temp2;

    cin >> n;
    cin >> m;

    vector< vector<int> > fmap(n + 1);
    vector<bool> fchkMap(n+1,0);    //check 맵 초기화용
    
    map = fmap;
    chkMap = fchkMap;

    while(m--)
    {
        cin >> temp1 >> temp2;
        map[temp2].push_back(temp1);
    }
    
    int max_cnt = 0;
    
    for(int i=1;i<=n;i++)
    {
        cnt = 0;
        dfs(i);

        if(cnt == max_cnt)
        {
            ans.push_back(i);
        }
        else if(cnt > max_cnt)
        {
            max_cnt = cnt;
            ans.clear();
            ans.push_back(i);
        }

        chkMap = fchkMap;
    }

    sort(ans.begin(), ans.end());

    for(int i=0;i<ans.size();i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    

    return 0;
}