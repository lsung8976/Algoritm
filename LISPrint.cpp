//boj.kr/14002
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> visual;
stack<int> stk;

void func(vector<int>& v, int index)
{
    if(index == 0) return;
    stk.push(v[index]);
    func(v, visual[index]);
}

int main()
{
    int T;
    int max = -987654321;   
    int indexMax = 0;

    cin >> T;
    vector<int> vec(T + 1, 0);
    vector<int> d(T + 1, 1);
    vector<int> fVisual(T + 1, 0);
    visual = fVisual;

    vec.push_back(0);   //vec[0] = 0;

    for(int i = 1; i <= T;i++)
    {
        cin >> vec[i];
    }

    if(T == 1)
    {
        cout << 1 << endl << vec[1] << endl;
        
    }
    else
    {
        for(int i = 1; i <= T; i++)
        {
            for(int j = i - 1; j >= 1; j--)
            {
                if(vec[j] < vec[i] && d[j] + 1 > d[i])
                {
                        d[i] = d[j] + 1;
                        visual[i] = j;
                }
            }
        }

        for(int i = 1; i <= T; i++)
        {
            if(max < d[i]) max = d[i];
            if(visual[indexMax] < visual[i]) indexMax = i;
        }

        
        func(vec, indexMax);
        
        cout << max << endl;

        while(!stk.empty())
        {
            cout << stk.top() << " ";
            stk.pop();
        }
        cout << endl;
    }

    return 0;
}