#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> numData(1000001, -1);

int func(int n)
{
    if(n == 1)  return 0;

    for(int i=2;i<=100000;i++)
    {
        numData[i] = numData[i - 1] + 1;

        if(numData[i] % 2 == 0)
        {
            int memoNum = numData[i / 2] + 1;
            numData[i] = (numData[i] > memoNum) ? memoNum : numData[i];
        }
        if(numData[i] % 3 == 0)
        {
            int memoNum = numData[i / 3] + 1;
            numData[i] = (numData[i] > memoNum) ? memoNum : numData[i];
        }
    }
    return numData[n];
}

int main()
{
    int N;
    cin >> N;

    numData[0] = 0;
    numData[1] = 1;
    numData[2] = 1;

    cout << func(N) << endl;
    
    return 0;
}