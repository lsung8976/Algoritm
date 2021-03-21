// boj.kr/11054(바이토닉)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    int max = -987654321;   
    
    cin >> T;
    vector<int> vec(T + 1, 0);
    vector<int> d(T + 1, 1);
    vector<int> d2(T + 1, 1);

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

    reverse(vec.begin(),vec.end());

    for(int i = 1; i <= T; i++)
    {
        for(int j = i - 1; j >= 1; j--)
        {
            if(vec[j] < vec[i])
            {
                    d2[i] = (d2[j] + 1 > d2[i]) ? d2[j] + 1: d2[i];
            }
        }
    }

    reverse(d2.begin(), d2.end());
    d2.insert(d2.begin(), 1);   //배열 0 자리 때문에 한칸씩 밀어주기

    for(int i = 1; i <= T; i++)
    {
        if(max < d[i] + d2[i] - 1)  max = d[i] + d2[i] - 1;
    }

    cout << max << endl;

    return 0;
}