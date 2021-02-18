//boj.kr/2193
#include <iostream>
#include <vector>
using namespace std;

vector<long long> d(1001, 0);

int main()
{
    int N;
    cin >> N;

    d[1] = 1;
    d[2] = 1;
    d[3] = 2;

    for(int i=4;i<=N;i++)
    {
        d[i] = d[i-1] + d[i-2];
    }

    cout << d[N] << endl;

    return 0;
}