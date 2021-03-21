// boj.kr/11053
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T;
    int max = -987654321;   
    
    cin >> T;
    vector<int> vec(T + 1, 0);
    vector<int> d(T + 1, 1);

    vec.push_back(0);   //vec[0] = 0;

    for(int i = 1; i <= T;i++)
    {
        cin >> vec[i];
    }

    for(int i = 1; i <= T; i++)
    {
        for(int j = i - 1; j >= 1; j--)
        {
            if(vec[j] < vec[i])
            {
                    d[i] = (d[j] + 1 > d[i]) ? d[j] + 1: d[i];
            }
        }
    }

    for(int i = 1; i <= T; i++)
    {
        if(max < d[i]) max = d[i];
    }
    cout << max << endl;

    return 0;
}