#include <iostream>
#include <vector>
using namespace std;


vector<long long> d(100001, 0);

int main()
{
    int T ;
    long long min = 987654321;
    cin >> T;

    d[0] = 0;
    d[1] = 1;
    d[2] = 2;
    d[3] = 3;

    for(int i=4;i<100001;i++)
    {
        for(int j = 1; j * j <= i; j++)
        {
            min = (d[i - j * j] + 1 < min) ? d[i - j * j] + 1 : min;
        }
        d[i] = min;
        min = 987654321;
    }

    cout << d[T] << endl;

    return 0;
}

