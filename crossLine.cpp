#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int compSide[4] = {1, 3, 4, 2};
int main()
{
    int size;
    int max = -987654321;
    int cnt = 0;
    vector<int> cntStg;
    cin >> size; 

    vector<vector<int>> map(size, vector<int>(size, 0));
    vector<pair<int, int>> container(size);

    for(int i=0;i<size;i++)
    {
        cin >> container[i].first;
        cin >> container[i].second;
        switch(container[i].first)
        {
            case 1 : container[i].first = compSide[0]; break;
            case 2 : container[i].first = compSide[1]; break; 
            case 3 : container[i].first = compSide[2]; break;
            case 4 : container[i].first = compSide[3]; break;
            default : break;
        }
        switch(container[i].first)
        {
            case 3 :
            case 4 : container[i].second = size - container[i].second; break;
            default : break;
        }
    }
    cout << endl;
    /*
    for(int i=0;i<size;i+=2)
    {
        cout << container[i].first << " " << container[i].second << " ";
        cout << container[i+1].first << " " << container[i+1].second << endl;
    }
    */
    for(int i = 0; i < size; i+=2)
    {
       for(int j=0;j<size;j++)
       {
           int bgn = container[i].first;
           int end = container[i+1].first;
           if(container[i].first > container[i+1].first) swap(bgn, end);
           if(i == j) continue;
           if(bgn <= container[j].first && container[j].first <= end)
           {
               if(bgn <= container[j].second && container[j].second <= end)
               {
                   cnt++;
               }
           }
       }
        //max = (max < cnt) ? cnt : max;
        cntStg.push_back(cnt);
        cnt = 0;
    }
    /*
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
            cout << map[i][j] << " ";
        cout << endl;
    }
    */

    // cout << max << endl;
    
    for(int i=0;i<cntStg.size();i++)
        cout<< cntStg[i] << " ";
    cout << endl;
    return 0;
}