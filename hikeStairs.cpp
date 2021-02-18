#include <iostream>
#include <vector>
using namespace std;



int main()
{
    int n;
    cin >> n;

    vector<int> p(n + 1);
    vector<int> d(10001,-1);
    for(int i=1;i<=n;i++)
    {
        cin >> p[i];
    }

    d[0] = 0;
    d[1] = p[1];
    d[2] = p[1] + p[2];

    for(int i=3;i<=n;i++)
    {
        d[i] = max(d[i-3] + p[i-1], d[i-2]) + p[i];
    }

    cout << d[n] << endl;

    return 0;
}