#include <iostream>
#include <vector>
using namespace std;

vector< int > d(10001, 0);

void fibonacci(int n) {
    if(n == 0)
    {
        cout << 1 << " " << 0 << endl;
    }
    else if(n == 1)
    {
        cout << d[0] << " " << d[1] << endl;
    }

    if(n >= 2)
    {
        for(int i =2; i <= n;i++)
        {
            d[i] = d[i-1] + d[i-2];
        }
        cout << d[n - 1] << " " << d[n] <<endl;
    }
}

int main()
{
    int num;
    int T;
    cin >> T;

    d[0] = 0;
    d[1] = 1;

    while(T--)
    {
        cin >> num;
        fibonacci(num);
    }

    return 0;
}