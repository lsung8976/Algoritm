#include <iostream>
#include <vector>
using namespace std;


vector<unsigned int> d(10001, 0);

unsigned int func(int n)
{
    if(d[n] > 0)    return d[n];

    for(int i=4;i<=n;i++)
    {
        d[i] = (d[i - 1] + d[i - 2] + d[i - 3]) % 1000000009;
    }

    return d[n];
}

int main()
{
    int T ;
    int temp;
    cin >> T;

    d[0] = 1;
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    for(int i=0;i<T;i++)
    {
        cin >> temp;
        cout << func(temp)<< endl;
    }


    return 0;
}