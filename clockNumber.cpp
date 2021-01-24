#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int clocknum(vector<int> vec)
{
    vector<int> ten = {1000,100,10,1};
    int min = 987654321;
    int num = 0;
    
    for(int i=0;i<4;i++)
    {
        for(int k=0;k<4;k++)
        {
            num += vec[(i+k)%4] * ten[k];
        }
        min = (min > num) ? num : min;
        num = 0;
    }
    
    return min;
}

int main()
{
    int cnt =0;
    vector<int> storage = {2, 1, 1 ,2};
    vector<int> allclocknum;
    int c_num;
    
    for(int i=0;i<storage.size();i++)
        cin >> storage[i];
    
    c_num = clocknum(storage);
    
    storage.clear();
    for(int i = 1111;i < 10000;i++)
    {
        bool chk = 0;
        string str = to_string(i);
        for(int j=0;j<4;j++)
        {
            if((str[j] - 48)==0)
            {
                storage.clear();
                str.clear();
                chk = 1;
                break;
            }
            storage.push_back(str[j] - 48);
        }
        if(chk)
        {
            chk = 0;
        }
        else
        {
            allclocknum.push_back(clocknum(storage));
            storage.clear();
        }
    }
    
    sort(allclocknum.begin(), allclocknum.end());
    allclocknum.erase(unique(allclocknum.begin(), allclocknum.end()), allclocknum.end());
    /*
    for(int i=0;i<allclocknum.size();i++)
        cout << allclocknum[i] << " ";
    cout << endl;
    */
    for(int i=0;i<allclocknum.size();i++)
    {
        if(allclocknum[i] > c_num)
            break;
        cnt++;
    }
    cout << allclocknum.size() << endl;
    cout << cnt << endl;
    return 0;
}