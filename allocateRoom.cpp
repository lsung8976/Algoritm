#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    int temp1;
    int temp2;
    int finish;
    int idx;
    int cnt =0;
    bool chk = true;

    cin >> N;
    vector< pair<int, int> > v;
    
    for(int i=0;i<N;i++)
    {
        scanf("%d", &temp1);
        scanf("%d", &temp2);
        v.push_back(make_pair(temp2, temp1));
    }
    
    sort(v.begin(), v.end());

    finish = v.front().first;
    idx = 0;
    cnt++;

    while(chk == 1)
    {
        chk = 0;
        for(int i=idx;i<v.size();i++)
        {
            if(v[i].second >= finish)
            {
                idx = i;
                finish = v[i].first;
                cnt++;
                chk = 1;
                break;
            }
        }
        if(chk == 1)    continue;

        chk = 0;
    }
    
    cout << cnt<< endl;

    return 0;
    
}